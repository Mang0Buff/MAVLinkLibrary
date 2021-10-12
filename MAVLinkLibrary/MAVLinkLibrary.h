#pragma once
#include "MultiVehicle.h"

using namespace System;

namespace MAVLinkLibrary {
	public ref class Library
	{
		// TODO: 여기에 이 클래스에 대한 메서드를 추가합니다.
	public:
		void CastToMAVLink(array<uint8_t>^ byte, int recvDataLength);
		void CastToMAVLinkTest();
		MultiVehicle multiVehicle;
		list<Vehicle^>::generic_container^ GetVehicleStatus();
	};
}
