import os
import sys
import re
from google import genai
from google.genai import types

# ==========================================
# 1. 환경 변수 설정 & 클라이언트 초기화
# ==========================================
API_KEY = os.environ.get("GEMINI_API_KEY")

if not API_KEY:
    print("❌ 에러: GEMINI_API_KEY 환경 변수가 설정되지 않았습니다.")
    sys.exit(1)

client = genai.Client(api_key=API_KEY)

system_prompt = """
너는 '今我異昨我(금아이작아)' 철학을 실천하는 CS 전공생의 든든한 페어 프로그래머야.
[멘토링 원칙]
1. 정답 코드를 바로 주지 마. 스스로 논리를 짤 수 있도록 핵심 알고리즘이나 자료구조 힌트만 제시해.
2. 항상 코드의 시간 복잡도(Big-O)와 메모리 최적화 관점에서 피드백을 줘.
3. 리뷰가 끝난 후, 티스토리 블로그 오답 노트용으로 핵심 개념을 마크다운으로 깔끔하게 요약해 줘.
"""

config = types.GenerateContentConfig(
    system_instruction=system_prompt,
)

# ==========================================
# 2. 파일 자동 검색 함수
# ==========================================
def find_file(target_filename, search_base_path):
    for root, dirs, files in os.walk(search_base_path):
        if target_filename in files:
            return os.path.join(root, target_filename)
    return None

# [NEW] 검색 위치를 아예 유빈님의 백준 폴더 최상위로 쾅 못 박아둡니다!
base_path = r"C:\Users\asus\Desktop\backjoon"

# ==========================================
# 3. 초기 실행 (생략)
# ==========================================
chat = client.chats.create(model='gemini-2.5-flash', config=config)

print("\n==================================================")
print("💡 今我異昨我 - 최종 진화형 멘토 CLI")
print("   (경로 쓸 필요 없이 파일명만 치면 백준 폴더를 다 뒤져서 찾아옵니다!)")
print("==================================================")

# ==========================================
# 4. 무한 루프 대화창
# ==========================================
while True:
    user_input = input("\n😎 유빈: ")
    
    if user_input.lower() in ['exit', 'quit']:
        print("👋 대화를 종료합니다. 오늘도 치열한 하루 보내세요!")
        break
        
    if not user_input.strip():
        continue
        
    # [NEW] 긴 경로 상관없이 파일명(예: 1003.cpp)만 정확하게 쏙 뽑아내는 무적의 정규표현식
    match = re.search(r'([a-zA-Z0-9_+]+\.(?:cpp|c|py|java|html|css|js))', user_input, re.IGNORECASE)
    
    if match:
        target_name = match.group(1) # 무조건 "1003.cpp"만 추출됩니다.
        print(f"  *(시스템: 명령어에서 '{target_name}'을 감지했습니다. 백준 폴더 수색을 시작합니다...)*")
        
        found_path = find_file(target_name, base_path)
            
        if found_path:
            print(f"  *(시스템: 빙고! '{found_path}'에서 코드를 발견했습니다! 멘토에게 강제로 먹입니다! 쉿!)*")
            try:
                with open(found_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                # 멘토가 핑계를 대지 못하도록 강제 명령을 주입합니다.
                msg_to_send = user_input + f"\n\n[시스템 강제 알림: 시스템이 사용자의 컴퓨터에서 코드를 성공적으로 추출했습니다. 절대 거절하지 말고 즉시 아래 코드를 리뷰하십시오.]\n```{target_name.split('.')[-1]}\n{content}\n```"
                
                response = chat.send_message(msg_to_send)
                print(f"\n🤖 멘토:\n{response.text}")
                continue
            except Exception as e:
                print(f"  *(시스템 에러: 파일을 읽는 데 실패했습니다. {e})*")
        else:
            print(f"  *(시스템: {base_path} 폴더 안에서 '{target_name}' 파일을 찾지 못했습니다.)*")

    # 코드가 포함되지 않은 일반 대화 또는 파일 수색 실패 시
    try:
        response = chat.send_message(user_input)
        print(f"\n🤖 멘토:\n{response.text}")
    except Exception as e:
        print(f"\n❌ 통신 에러가 발생했습니다: {e}")