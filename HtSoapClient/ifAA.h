#ifndef ifChengDao_h__
#define ifChengDao_h__

#include <stdio.h>
#include <string>

//Υ��ͼƬ
typedef struct
{
	/*login���ص�sid*/
	char *sid;
	/*�豸���*/
	char *pDeviceId;
	/*�������*/
	char *pVehicleId;
	/*�豸����*/
	char *pDeviceType;
	/*������*/
	char *pDirectionId;
	/*�������*/
	char *pDriveWayId;
	/*���ƺ���*/
	char *pPlateNum;
	/*��������*/
	char *pPlateType;
	/*����ʱ��*/
	char *pPassTime;
	/*��ƿ�ʼʱ��*/
	char *pRedStartTime;
	/*��Ƴ���ʱ��*/
	char *pRedLastTime;
	/*�����ٶ�*/
	long nSpeed;
	/*������*/
	long nLargeLimitSpeed;
	/*С������*/
	long nMinLimitSpeed;
	/*Υ����Ϊ����*/
	char *pIllegalType;
	/*�ɿ�*/
	char *pIllegalType2;
	/*���� ������Ϊ��λ �ɿ�*/
	long nCarLen;
	/*������ɫ*/
	char *pPlateColor;
	/*��������*/
	char *pVehType;
	/*ͼƬ1 ������*/
	unsigned char *__ptr1;
    int   __size1;

	/*ͼƬ2 ������*/
	unsigned char *__ptr2;
    int   __size2;

	/*ͼƬ1 ������*/
	unsigned char *__ptr3;
    int   __size3;

	/*ͼƬ1 ������*/
	unsigned char *__ptr4;
    int   __size4;

	/*ͼƬ5 ����ͼƬ ������*/
	unsigned char *__ptr5;
    int   __size5;

	/*ͼƬ6 ������д ������*/
	unsigned char *__ptr6;
    int   __size6;

	/*��Ƶ ������*/
	unsigned char *__ptrVideo;
    int   __sizeVideo;

	/*ͼƬԶ�̷���·�� �ɿ�*/
	char *__pRemoteData;
	/*Υ����� 0��ͨ��¼  1Υ����¼�ǿ�*/
	char *pViolate;
    /*���ͱ�־ "0"��������  "1"�����ͺ��� �ǿ�*/
	char *pSendType;
	/*Υ���ص����*/
	char *pPlaceId;
	/*Υ���ص�����*/
	char *pPlaceName;
	/*������ɫ*/
	char *pCarColor;
    /*�������*/
    
	/*�����ֶ�1*/
	char *pReseve1;
	/*�����ֶ�2*/
	char *pReseve2;
	/*�����ֶ�3*/
	char *pReseve3;
}TChengDao_VioInfo;

typedef struct
{
	/*login���ص�sid*/
	char *pSid;
	/*������Ϣ��*/
	char *pXmlData;
	/*ͼƬ1 ����ȫ��ͼ ������*/
	unsigned char *__ptr1;
    int   __size1;
	/*ͼƬ2 ȫ��ͼƬ ������*/
	unsigned char *__ptr2;
    int   __size2;
	/*ͼƬ3 ȫ��ͼƬ2 ������*/
	unsigned char *__ptr3;
    int   __size3;    
	/*ͼƬ4 ���� ������*/
	unsigned char *__ptr4;
    int   __size4;
	/*ͼƬ5 ����ͼƬ ������*/
	unsigned char *__ptr5;
    int   __size5;
	/*ͼƬ6 ������д ������*/
	unsigned char *__ptr6;
    int   __size6;

	/*��Ƶ ������*/
	unsigned char *__ptrVideo;
    int   __sizeVideo;

}TChengDao_VehPassInfo;

#ifdef __cplusplus
extern "C" {
#endif

#ifndef API
#ifdef _MSC_VER
#define API   __declspec(dllexport)
#else
#define API
#endif
#endif

    API int ifChengDao__login(char *soap_endpoint, char *pDeviceId, char *pDeviceKey, char *szSidOut);

    API int ifChengDao__logout(char *soap_endpoint, char *sId);


	API int ifChengDao__setIllegalVehInfo(char *soap_endpoint, TChengDao_VioInfo *ptData);

	API int ifChengDao__setPassVehInfo(char *soap_endpoint, TChengDao_VehPassInfo *ptData);

#ifdef __cplusplus
}
#endif

#endif // ifChengDao_h__
