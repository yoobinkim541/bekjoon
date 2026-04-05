# 💡 Baekjoon AI Mentor CLI

> 백준 문제 풀이를 보조해주는 Gemini 기반 CLI 개발 프로젝트
> 알고리즘 문제 풀이와 코드 리뷰를 도와주는 터미널 환경의 AI 페어 프로그래머 CLI입니다.

![Python](https://img.shields.io/badge/Python-3776AB?style=flat-square&logo=python&logoColor=white)
![Gemini](https://img.shields.io/badge/Gemini%20API-8E75B2?style=flat-square&logo=googlebard&logoColor=white)

## 📌 프로젝트 소개
알고리즘 문제를 풀다가 막혔을 때, 터미널 창을 벗어나지 않고 즉각적인 피드백을 받을 수 있는 도구입니다. 정답 코드를 바로 떠먹여 주는 대신, 스스로 논리를 전개할 수 있도록 핵심 알고리즘 힌트와 시간 복잡도(Big-O), 메모리 최적화 관점에서의 리뷰를 제공합니다.

## ✨ 주요 기능

* **자동 파일 탐색 및 코드 첨부 (Auto File Discovery)**
  * 채팅창에 파일명(예: `1003.cpp`, `main.py`)을 입력하면, 프로그램을 실행한 현재 폴더와 하위 폴더를 자동으로 수색하여 코드를 AI에게 전달합니다.
  * 복잡한 절대 경로를 입력할 필요가 없습니다.
* **CS 전공생 맞춤형 멘토링**
  * 단순한 코드 생성을 지양하고, 자료구조와 알고리즘의 원리를 깨우칠 수 있도록 유도합니다.
* **블로그 오답 노트 포매팅**
  * 대화 중 "마크다운으로 정리해 줘"라고 명시적으로 요청할 때만, 티스토리 등 개발 블로그에 바로 올릴 수 있는 깔끔한 마크다운 요약본을 생성합니다.

## 🚀 설치 및 실행 방법

### 1. 요구 사항 (Prerequisites)
* Python 3.8 이상
* Google Gemini API Key (무료 발급 가능)

### 2. 라이브러리 설치
```bash
pip install google-genai
