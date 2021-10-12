#include "pch.h"
#include "MAVLinkLibrary.h"

using MAVLinkLibrary::Library;

list<Vehicle^>::generic_container^ Library::GetVehicleStatus()
{
	return multiVehicle.getvehicle();
}

struct DroneStatusManager
{
public:
	int latitude;
	int longitude;
};

mavlink_status_t status;
mavlink_message_t msg;
int chan = MAVLINK_COMM_0;

DroneStatusManager droneStatusManager[10];

void Library::CastToMAVLinkTest()
{
	mavlink_global_position_int_t packet_in = {
		963497464,963497672,963497880,963498088,963498296,18275,18379,18483,18587
	};
	array<uint8_t>^ sendMsg;
	mavlink_msg_global_position_int_encode(0x01, 0x01, &msg, &packet_in);
}


void Library::CastToMAVLink(array<uint8_t>^ byte, int recvDataLength)
{
	for (int position = 0; position < recvDataLength; position++)
	{
		if (mavlink_parse_char(chan, byte[position], &msg, &status))
		{
			switch (msg.msgid)
			{
			case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: // ID for GLOBAL_POSITION_INT

				mavlink_global_position_int_t globalPosition;
				// Get all fields in payload (into global_position)

				mavlink_msg_global_position_int_decode(&msg, &globalPosition);


				printf("%d", globalPosition.lat);

				break;
			case MAVLINK_MSG_ID_GPS_RTCM_DATA:
				mavlink_gps_rtcm_data_t gps_rtcm_data_msg;
				mavlink_msg_gps_rtcm_data_decode(&msg, &gps_rtcm_data_msg);



				printf("RTCM DATA");
				break;
			default:
				break;

			}
		}
	}
	
}
