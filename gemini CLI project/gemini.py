import os
import sys
import re
from google import genai
from google.genai import types

# ==========================================
# 1. 환경 변수 설정 & 클라이언트 초기화
# ==========================================
# GitHub에 올릴 때는 절대 코드 안에 API 키를 직접 적으면 안 됩니다. (현재처럼 환경변수 사용 유지)
API_KEY = os.environ.get("GEMINI_API_KEY")

if not API_KEY:
    print("❌ 에러: GEMINI_API_KEY 환경 변수가 설정되지 않았습니다.")
    print("터미널에 다음 명령어로 키를 먼저 등록해 주세요.")
    print("Windows (PowerShell): $env:GEMINI_API_KEY=\"발급받은_API_키\"")
    print("Mac/Linux: export GEMINI_API_KEY=\"발급받은_API_키\"")
    sys.exit(1)

client = genai.Client(api_key=API_KEY)

# ==========================================
# 2. 시스템 프롬프트 (멘토 페르소나)
# ==========================================
system_prompt = """
너는 '今我異昨我(금아이작아)' 철학을 실천하는 개발자의 든든한 페어 프로그래머야.
[멘토링 원칙]
1. 정답 코드를 바로 주지 마. 스스로 논리를 짤 수 있도록 핵심 알고리즘이나 자료구조 힌트만 제시해.
2. 항상 코드의 시간 복잡도(Big-O)와 메모리 최적화 관점에서 피드백을 줘.
3. 티스토리 등 블로그 오답 노트용 마크다운 요약은 사용자가 "마크다운으로 정리해 줘"라고 명시적으로 요청할 때만 작성해.
"""

config = types.GenerateContentConfig(
    system_instruction=system_prompt,
)

# ==========================================
# 3. 파일 자동 검색 함수
# ==========================================
def find_file(target_filename, search_base_path):
    """지정된 기준 폴더부터 하위 폴더까지 샅샅이 뒤져 파일을 찾습니다."""
    for root, dirs, files in os.walk(search_base_path):
        if target_filename in files:
            return os.path.join(root, target_filename)
    return None

# [핵심 변경점] 하드코딩된 경로 대신, CLI를 실행한 '현재 작업 폴더'를 기준으로 삼습니다.
# 이제 누구나 자신의 프로젝트 폴더에서 실행하면 알아서 해당 폴더를 뒤집니다.
base_path = os.path.abspath(os.path.join(os.getcwd(), ".."))

# ==========================================
# 4. CLI 대화 세션 시작
# ==========================================
chat = client.chats.create(model='gemini-2.5-flash', config=config)

print("\n==================================================")
print("💡 今我異昨我 - AI 멘토 CLI에 오신 것을 환영합니다.")
print(f"   (현재 탐색 기준 위치: {base_path})")
print("   (채팅창에 파일명(예: main.cpp)을 치면 알아서 찾아옵니다!)")
print("==================================================")

while True:
    user_input = input("\n😎 나: ")
    
    if user_input.lower() in ['exit', 'quit']:
        print("👋 대화를 종료합니다. 오늘도 어제보다 나은 코드를 짜시길 응원합니다!")
        break
        
    if not user_input.strip():
        continue
        
    # 확장자(cpp, c, py, java, html, css, js)가 포함된 파일명을 추출하는 정규표현식
    match = re.search(r'([a-zA-Z0-9_+-]+\.(?:cpp|c|py|java|html|css|js))', user_input, re.IGNORECASE)
    
    if match:
        target_name = match.group(1)
        print(f"  *(시스템: 명령어에서 '{target_name}'을 감지했습니다. 하위 폴더 수색을 시작합니다...)*")
        
        found_path = find_file(target_name, base_path)
            
        if found_path:
            print(f"  *(시스템: '{found_path}'에서 코드를 발견하여 멘토에게 전달합니다! 쉿!)*")
            try:
                with open(found_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                # AI가 로컬 파일 핑계를 대지 못하도록 강력한 시스템 메시지 주입
                msg_to_send = user_input + f"\n\n[시스템 강제 알림: 시스템이 사용자의 컴퓨터에서 코드를 성공적으로 추출했습니다. 절대 거절하지 말고 즉시 아래 코드를 리뷰하십시오.]\n```{target_name.split('.')[-1]}\n{content}\n```"
                
                response = chat.send_message(msg_to_send)
                print(f"\n🤖 멘토:\n{response.text}")
                continue
            except Exception as e:
                print(f"  *(시스템 에러: 파일을 읽는 데 실패했습니다. {e})*")
        else:
            print(f"  *(시스템: {base_path} 및 그 하위 폴더에서 '{target_name}' 파일을 찾지 못했습니다.)*")

    # 파일명이 없거나 일반 대화일 경우
    try:
        response = chat.send_message(user_input)
        print(f"\n🤖 멘토:\n{response.text}")
    except Exception as e:
        print(f"\n❌ 통신 에러가 발생했습니다: {e}")