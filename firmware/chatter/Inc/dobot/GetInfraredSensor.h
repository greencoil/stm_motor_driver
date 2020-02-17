#ifndef _ROS_SERVICE_GetInfraredSensor_h
#define _ROS_SERVICE_GetInfraredSensor_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dobot
{

static const char GETINFRAREDSENSOR[] = "dobot/GetInfraredSensor";

  class GetInfraredSensorRequest : public ros::Msg
  {
    public:
      typedef int32_t _infraredPort_type;
      _infraredPort_type infraredPort;

    GetInfraredSensorRequest():
      infraredPort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_infraredPort;
      u_infraredPort.real = this->infraredPort;
      *(outbuffer + offset + 0) = (u_infraredPort.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_infraredPort.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_infraredPort.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_infraredPort.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->infraredPort);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_infraredPort;
      u_infraredPort.base = 0;
      u_infraredPort.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_infraredPort.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_infraredPort.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_infraredPort.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->infraredPort = u_infraredPort.real;
      offset += sizeof(this->infraredPort);
     return offset;
    }

    const char * getType(){ return GETINFRAREDSENSOR; };
    const char * getMD5(){ return "7fd40c1b7cc5e35cf14af88242c5f0d0"; };

  };

  class GetInfraredSensorResponse : public ros::Msg
  {
    public:
      typedef int32_t _result_type;
      _result_type result;
      typedef uint8_t _value_type;
      _value_type value;

    GetInfraredSensorResponse():
      result(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_result.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_result.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_result.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->result);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_result.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->result = u_result.real;
      offset += sizeof(this->result);
      this->value =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return GETINFRAREDSENSOR; };
    const char * getMD5(){ return "73a59c0cb161215c2b7c0a18034c4f90"; };

  };

  class GetInfraredSensor {
    public:
    typedef GetInfraredSensorRequest Request;
    typedef GetInfraredSensorResponse Response;
  };

}
#endif
