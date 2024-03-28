# C_SSD_PJ

 C 언어를 사용해 SSD 제품을 테스트 할 수 있는 Test Shell을 제작합니다.
 1. SSD를 가상으로 프로그래밍으로 구현합니다.
 2. Test Shell 프로그램을 제작하여 SSD 동작을 테스트 할 수 있다.
 3. 다양한 Test Script를 제작한다.
    
![image](https://github.com/wooyoungman/C_SSD_PJ/assets/101693311/b305eeb8-d8de-4f05-8349-c25524834faa)

---

## 목표

이 프로젝트의 목표는 C 프로그래밍을 사용하여 SSD 컨트롤러의 역할을 구현하는 것입니다. SSD의 용량은 400바이트로 가정하며, 논리 블록 주소 (LBA)는 각각 4바이트입니다. 

---

## 구현 순서
1. SSD
   * HW를 SW로 구현한다
2. Test Shell Application
   * 테스트 프로그램
3. Test Script
   * 테스트 프로그램 (API)

최종 제작해야하는 소스코드 2개

ssd.c

testshell.c

write R 0x????????-> nand.txt에 해당하는 LBA R에 0x???????? 저장 


read R -> nand.txt에 해당하는 LBA R을 result.txt에 저장


---


## 빌드 방법 (Ubuntu 20.04)


gcc -o shell source.c

gcc -o ssd ssd.c

nand.txt (초기 400바이트 이기 때문에 0 800개 설정)

result.txt (초기 설정 x, 하나의 LBA만 읽어옴)


명령어
write: SSD에 쓰기 (예: write 3 0x12345678)

read: 특정 LBA 읽기 (예: read 3)

fullwrite: 전체 SSD에 쓰기 (예: fullwrite 0x13467988)

fullread: 전체 SSD 읽기 (예: fullread)


exit: 쉘 종료 (예: exit)

help: 명령어 표시 (예: help)
