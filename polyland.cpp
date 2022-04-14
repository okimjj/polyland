#include <stdio.h>

int main () {
	const int YEAR_NOW = 2022;
	const int MONTH_NOW = 4;
	const int TODAY = 14;
	
	const int BABY = 15000;
	const int KID_DAY = 47000;
	const int KID_NIGHT = 36000;
	const int YOUNG_DAY = 54000;
	const int YOUNG_NIGHT = 43000;
	const int ADULT_DAY = 62000; 
	const int ADULT_NIGHT = 50000; 
	
	const float DC_DIS_NAT_PREG = 0.5;
	const float DC_SOLDIER = 0.49;
	const float DC_MULTIKID = 0.3;
	
	int dayOrNight;
	char jumin[7];
	int birthYear;
	int birthMonth;
	int birthDate;
	int age;
	int numberOfTicket = 0;
	int discountCondition;
	int price = 0;
	int priceFinal = 0; 
	int repeat;

	do {
	
	
		printf("권종을 선택하세요.\n1. 주간권\n2. 야간권\n");
		printf("번호 입력: ");
		scanf("%d", &dayOrNight);
		
		printf("****************************************\n");
		printf("주민등록번호 7번째 자리까지 입력하세요\n");
		printf("주민번호: ");
		scanf("%s", &jumin);
		
		do {
		printf("****************************************\n");
		printf("몇 장을 주문하시나요? (10장 초과 시 무효)\n"); 
		printf("장 수: ");
		scanf("%d", &numberOfTicket);
		} while (numberOfTicket > 10);
		
		printf("****************************************\n");
		printf("우대사항을 선택하세요.\n");
		printf("1. 장애인\n2. 국가유공자\n3. 임산부\n4. 휴가장병\n5. 다둥이\n6. 없음\n");
		printf("번호 입력: ");
		scanf("%d", &discountCondition);
		
			//주민번호 7번째 자리가 1이거나 2라면 1900년대 생, 3이나 4라면 2000년대 생
		if ((jumin[6] - '0') == 1 || (jumin[6] - '0') == 2) {
			birthYear = 1900 + ((jumin[0] - '0') * 10 + (jumin[1] - '0'));
		} else if ((jumin[6] - '0') == 3 || (jumin[6] - '0') == 4) {
			birthYear = 2000 + ((jumin[0] - '0') * 10 + (jumin[1] - '0'));
		}
		//생월 = 주민번호 3,4번째 자리
		birthMonth = ((jumin[2] - '0') * 10) + (jumin[3] - '0');
		birthDate = ((jumin[4] - '0') * 10) + (jumin[5] - '0');
		
		 
		if ((birthYear <= YEAR_NOW && birthMonth < MONTH_NOW) || (birthYear <= YEAR_NOW && birthMonth == MONTH_NOW && birthDate < TODAY)) {
			age = (YEAR_NOW - birthYear); //생년이 지났거나 올해 태어난 사람 중 생월이 지난 사람,  4월생인데 생일이 지난 사람은 올해 - 생년 = 나이
		} else if ((birthYear < YEAR_NOW && birthMonth > MONTH_NOW) || (birthYear < YEAR_NOW && birthMonth == MONTH_NOW && birthDate > TODAY)) { 
			age = (YEAR_NOW - birthYear) - 1; // 생일이 아직 오지 않은 사람은 "(올해 - 생년) - 1 = 나이" 
		}
		
		if (dayOrNight == 1) {
			if (age >= 0 && age <= 3 || (age > 64)) {
				price = BABY * numberOfTicket;
			} else if (age > 3 && age < 13) {
				price = KID_DAY * numberOfTicket;
			} else if (age > 13 && age < 19) {
				price = YOUNG_DAY * numberOfTicket;
			} else if (age > 18 && age < 65) {
				price = ADULT_DAY * numberOfTicket;
			}
		}
		
		if (dayOrNight == 2) {
			if (age >= 0 && age <= 3 || age > 64) {
				price = BABY * numberOfTicket;
			} else if (age > 13 && age < 19) {
				price = YOUNG_NIGHT * numberOfTicket;
			} else if (age > 18 && age < 65) {
				price = ADULT_NIGHT * numberOfTicket;
			}
		}
		
		if (discountCondition == 1 || discountCondition == 2 || discountCondition == 3) {
			price = price - (price * DC_DIS_NAT_PREG);
		} else if (discountCondition == 4) {
			price = price - (price * DC_SOLDIER);
		} else if (discountCondition == 5) {
			price = price - (price * DC_MULTIKID);
		}
		
		printf("****************************************\n");
		printf("가격은 %d원입니다. 감사합니다.\n", price);
		printf("계속 발권하시겠습니까?[1. 예 / 2. 아니오]\n");
		printf("입력: ");
		scanf ("%d", &repeat);
		printf("\n**************************************\n");
		
		priceFinal = priceFinal + price;
		
	} while (repeat == 1);
			printf("티켓 발권을 종료합니다. 감사합니다.\n");
			printf("*************폴리랜드**************\n");
			printf("총 결제액: %d", priceFinal);
			
	return 0; 
}
