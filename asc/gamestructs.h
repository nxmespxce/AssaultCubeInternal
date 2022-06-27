#pragma once

#include "stdafx.h"

#define dwLocalPlayer 0x10F4F4
#define dwEntityList 0x10F4F8

struct Vector3 {
	float x, y, z;
};

class Entity
{
public:
	class PlayerState* pPlayerState; //0x0000
	Vector3 vHead; //0x0004
	char pad_0010[24]; //0x0010
	int32_t iForward; //0x0028
	int32_t iRight; //0x002C
	char pad_0030[4]; //0x0030
	Vector3 vOrigin; //0x0034
	Vector3 vAngles; //0x0040
	char pad_004C[29]; //0x004C
	int16_t bGrounded; //0x0069
	char pad_006B[5]; //0x006B
	int32_t bSteadyAim; //0x0070
	char pad_0074[132]; //0x0074
	int32_t iHealth; //0x00F8
	int32_t iShield; //0x00FC
	char pad_0100[20]; //0x0100
	int32_t iSecondaryReserve; //0x0114
	char pad_0118[16]; //0x0118
	int32_t iPrimaryReserve; //0x0128
	char pad_012C[16]; //0x012C
	int32_t iSecondaryMag; //0x013C
	char pad_0140[16]; //0x0140
	int32_t iPrimaryMag; //0x0150
	char pad_0154[544]; //0x0154
	class Weapon* pCurrentWeapon; //0x0374
}; //Size: 0x0378

class PlayerState
{
public:
	char pad_0000[132]; //0x0000
}; //Size: 0x0084

class Weapon
{
public:
	char pad_0000[12]; //0x0000
	char* sName; //0x000C
	class WeaponInfo* pWeaponInfo; //0x0010
	class Magazine* pMagazine; //0x0014
	char pad_0018[4]; //0x0018
	int32_t iShotsFired; //0x001C
	char pad_0020[16]; //0x0020
}; //Size: 0x0030

class Magazine
{
public:
	int32_t Ammo; //0x0000
	char pad_0004[76]; //0x0004
	int32_t iTotalShots; //0x0050
}; //Size: 0x0054

class WeaponInfo
{
public:
	int32_t iReserveAmmo; //0x0000
	char pad_0004[36]; //0x0004
	int32_t iCurrentAmmo; //0x0028
	char pad_002C[76]; //0x002C
	int32_t iTotalShots; //0x0078
	char pad_007C[149]; //0x007C
	char sOwnerName[16]; //0x0111
}; //Size: 0x0120