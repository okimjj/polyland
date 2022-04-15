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
	const int SAVE_AGE_TYPE = 1;
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
	int orderList [][] = {0};
	

	do {
	
	
		printf("������ �����ϼ���.\n1. �ְ���\n2. �߰���\n");
		printf("����: ");
		scanf("%d", &dayOrNight);
		
		printf("****************************************\n");
		printf("�ֹε�Ϲ�ȣ 7��° �ڸ����� �Է��ϼ���\n");
		printf("�ֹι�ȣ: ");
		scanf("%s", &jumin);
		
		do {
		printf("****************************************\n");
		printf("�� ���� �ֹ��Ͻó���? (10�� �ʰ� �� ��ȿ)\n"); 
		printf("����: ");
		scanf("%d", &numberOfTicket);
		} while (numberOfTicket > 10);
		
		printf("****************************************\n");
		printf("�������� �����ϼ���.\n");
		printf("1. �����\n2. ����������\n3. �ӻ��\n4. �ް��庴\n5. �ٵ���\n6. ����\n");
		printf("����: ");
		scanf("%d", &discountCondition);
		
			//�ֹι�ȣ 7��° �ڸ��� 1�̰ų� 2��� 1900��� ��, 3�̳� 4��� 2000��� ��
		if ((jumin[6] - '0') == 1 || (jumin[6] - '0') == 2) {
			birthYear = 1900 + ((jumin[0] - '0') * 10 + (jumin[1] - '0'));
		} else if ((jumin[6] - '0') == 3 || (jumin[6] - '0') == 4) {
			birthYear = 2000 + ((jumin[0] - '0') * 10 + (jumin[1] - '0'));
		}
		//���� = �ֹι�ȣ 3,4��° �ڸ�
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
			ageGroup = AGR_GROUP_ELDER;
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
		printf("������ %d���Դϴ�. �����մϴ�.\n", price);
		printf("��� �߱��Ͻðڽ��ϱ�?[1. �� / 2. �ƴϿ�]\n");
		printf("����: ");
		scanf ("%d", &repeat);
		printf("\n**************************************\n");
		
		priceFinal = priceFinal + price;
		roundCount ++;
		
		orderList[roundCount][SAVE_TICKET_TYPE] = dayOrNight;
		orderList[roundCount][SAVE_AGE_GROUP] = ageGroup;
		orderList[roundCount][SAVE_TICKET_COUNT] = numberOfTicket;
		orderList[roundCount][SAVE_PRICE_PER_PURCHASE] = price;
		orderList[roundCount][SAVE_DISCOUNT] = discountCondition;
		orderList[roundCount][SAVE_TOTAL] = priceFinal;
		
	} while (repeat == 1);
	
		printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n");
		printf("\n*************��������**************\n");
		for (int index = 0; index < roundCount; index++) {
			if () //������� �ٽ� 
		}
		printf("�� �������� %d���Դϴ�.", priceFinal);
		
	return 0;
}
