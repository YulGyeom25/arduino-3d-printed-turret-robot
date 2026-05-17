<img width="960" height="1280" alt="6269494290782294095" src="https://github.com/user-attachments/assets/0b03676b-68dc-441c-a0be-efa18c6219b3" />

# Arduino 기반 3D 프린팅 커브볼 터렛 프로토타입

이 프로젝트는 휘어지는 탁구공을 발사하기 위한 3D 프린팅 기반 터렛형 발사대 프로토타입입니다.

이 프로젝트의 핵심 아이디어는 두 개의 발사 휠 회전 속도를 제어하여 탁구공에 회전을 만들고, 이를 통해 휘어지는 궤적을 구현하는 것입니다. 프로젝트에는 Arduino 제어 코드, 3D 프린팅용 STL 파일, 그리고 설계 과정에서 사용한 계산 자료가 포함되어 있습니다.

## 프로젝트 상태

현재 이 모델은 프로토타입 단계입니다.

일부 STL 모델에는 약간의 설계 오류나 기구적 문제가 있을 수 있으므로, 안정적인 조립과 동작을 위해서는 추가적인 수정 및 재설계가 필요합니다.

## 프로젝트 개요

이 프로젝트의 목표는 서로 다른 휠 속도를 이용하여 탁구공의 궤적을 휘게 만들 수 있는 발사대를 설계하고 테스트하는 것입니다.

이 프로젝트에는 다음과 같은 요소가 포함되어 있습니다.

- Arduino 기반 모터 및 서보모터 제어 (관절 위치 제어, 발사를 위한 휠의 속도 제어)
- 3D 프린팅 기구 부품
- 2휠 발사 메커니즘
- 서보모터 기반 각도 제어
- 토크 계산 자료
- 모터 선정 및 탁구공 궤적 분석을 위한 시뮬레이션/계산 코드

## 프로젝트 구조

```text
.
├── README.md
├── .gitignore
│
├── arduino/
│   └── final_integration/
│       └── final_integration.jpg.ino
│
├── stl/
│   ├── cover.stl
│   ├── main.stl
│   ├── muzzle.stl
│   ├── pillar.stl
│   ├── shooter.stl
│   ├── Turret_arm_final.stl
│   ├── Turret_Body.stl
│   ├── wheel.stl
│   ├── base_connecter.stl
│   ├── base_final.stl
│   ├── body_final.stl
│   └── connecter.stl
│
└── docs/
    └── 3축_자동화_로봇.xlsx
    └── turret_trajectory_calculator.py
    └── 터렛_최대rpm_계산기.py
