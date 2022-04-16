#include <stdio.h>

int main () {
	const int YEAR_NOW = 2022;
	const int MONTH_NOW = 4;
	const int TODAY = 14;
	
	const int AGE_GROUP_BABY = 1;
	const int AGE_GROUP_KID = 2;
	const int AGE_GROUP_YOUNG = 3;
	const int AGE_GROUP_ADULT = 4;
	const int AGE_GROUP_ELDER = 5;
	
	const int SAVE_TICKET_TYPE = 0;
	const int SAVE_AGE_GROUP = 1;
	const int SAVE_TICKET_COUNT = 2;
	const int SAVE_PRICE_PER_PURCHASE = 3;
	const int SAVE_DISCOUNT = 4;
	
	const int BABY = 15000;
	const int KID_DAY = 46000;
	const int KID_NIGHT = 35000;
	const int YOUNG_DAY = 52000;
	const int YOUNG_NIGHT = 41000;
	const int ADULT_DAY = 59000; 
	const int ADULT_NIGHT = 47000; 
	
	const float DC_DIS_NAT_PREG = 0.5;
	const float DC_SOLDIER = 0.49;
	const float DC_MULTIKID = 0.3;
	
	int dayOrNight;
	char jumin[7];
	int birthYear;
	int birthMonth;
	int birthDate;
	int age;
	int ageGroup;
	int numberOfTicket = 0;
	int discountCondition;
	int price = 0;
	int priceFinal = 0; 
	int repeat;
	int roundCount = 0;
	int orderList [10][10] = {0};
	

	do {
	
	
		printf("권종을 선택하세요.\n1. 주간권\n2. 야간권\n");
		printf("선택: ");
		scanf("%d", &dayOrNight);
		
		printf("****************************************\n");
		printf("주민등록번호 7번째 자리까지 입력하세요\n");
		printf("주민번호: ");
		scanf("%s", &jumin);
		
		do {
		printf("****************************************\n");
		printf("몇 장을 주문하시나요? (10장 초과 시 무효)\n"); 
		printf("수량: ");
		scanf("%d", &numberOfTicket);
		} while (numberOfTicket > 10);
		
		printf("****************************************\n");
		printf("우대사항을 선택하세요.\n");
		printf("1. 장애인\n2. 국가유공자\n3. 임산부\n4. 휴가장병\n5. 다둥이\n6. 없음\n");
		printf("선택: ");
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
		
		 
		if (MONTH_NOW > birthMonth || (MONTH_NOW == birthMonth && TODAY >= birthDate)) {
			age = YEAR_NOW - birthYear;
		} else {
			age = YEAR_NOW - birthYear - 1;
		}
		
		if (age >=0 && age < 3) {
			ageGroup = AGE_GROUP_BABY;
		} else if (age >= 3 && age < 13) {
			ageGroup = AGE_GROUP_KID;
		} else if (age >= 13 && age < 19 ) {
			ageGroup = AGE_GROUP_YOUNG;
		}else if (age >= 19 && age < 65) {
			ageGroup = AGE_GROUP_ADULT;
		}else if (age >= 65) {
			ageGroup = AGE_GROUP_ELDER;
		}
		
		if (dayOrNight == 1) {
			if (age >= 0 && age < 3 || (age > 64)) {
				price = BABY * numberOfTicket;
			} else if (age >= 3 && age < 13) {
				price = KID_DAY * numberOfTicket;
			} else if (age >= 13 && age < 19) {
				price = YOUNG_DAY * numberOfTicket;
			} else if (age >= 19 && age < 65) {
				price = ADULT_DAY * numberOfTicket;
			}
		}
		
		if (dayOrNight == 2) {
			if (age >= 0 && age <= 3 || age >= 65) {
				price = BABY * numberOfTicket;
			} else if (age >= 13 && age < 19) {
				price = YOUNG_NIGHT * numberOfTicket;
			} else if (age >= 19 && age < 65) {
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
		printf("선택: ");
		scanf ("%d", &repeat);
		printf("\n**************************************\n");
		
		roundCount ++;
		priceFinal = priceFinal + price;
		
		orderList[roundCount][SAVE_TICKET_TYPE] = dayOrNight;
		orderList[roundCount][SAVE_AGE_GROUP] = ageGroup;
		orderList[roundCount][SAVE_TICKET_COUNT] = numberOfTicket;
		orderList[roundCount][SAVE_PRICE_PER_PURCHASE] = price;
		orderList[roundCount][SAVE_DISCOUNT] = discountCondition;
		
	} while (repeat == 1);
	
		printf("티켓 발권을 종료합니다. 감사합니다.\n");
		printf("\n*************폴리랜드**************\n");
		for (int index = 0; index < roundCount; index++) { //다시,,,
			if (orderList[roundCount][SAVE_TICKET_TYPE] == 1) {
				printf("주간권\t");
			} else if (orderList[roundCount][SAVE_TICKET_TYPE] == 2) {
				printf("야간권\t");
			}
			
			if (orderList[roundCount][SAVE_AGE_GROUP] == 1) {
				printf("베이비\t");
			} else if (orderList[roundCount][SAVE_AGE_GROUP] == 2) {
				printf("어린이\t");
			} else if (orderList[roundCount][SAVE_AGE_GROUP] == 3) {
				printf("청소년\t");
			} else if (orderList[roundCount][SAVE_AGE_GROUP] == 4) {
				printf("성인\t");
			} else if (orderList[roundCount][SAVE_AGE_GROUP] == 5) {
				printf("노인\t");
			}
			
			printf ("%d 장\t", orderList[roundCount][SAVE_TICKET_COUNT]);
			
			if (orderList[roundCount][SAVE_DISCOUNT] == 1) {
				printf("%d원 (장애인 할인)\n", price);
			} else if (orderList[roundCount][SAVE_DISCOUNT] == 2) {
				printf("%d원 (국가유공자 할인)\n", price);
			} else if (orderList[roundCount][SAVE_DISCOUNT] == 3) {
				printf("%d원 (임산부 할인)\n", price);
			} else if  (orderList[roundCount][SAVE_DISCOUNT] == 4) {
				printf("%d원 (휴가장병 할인)\n", price);
			} else if (orderList[roundCount][SAVE_DISCOUNT] == 5) {
				printf("%d원 (다둥이 할인)\n", price);
			} else {
				printf("%d원 (할인 없음)\n", price);
			}
		}
		printf("==================================\n");
		printf("총 결제액은 %d원입니다.", priceFinal);
		
	return 0;
}
