#ifndef _ROS_SERVICE_get_al_dish_from_rack_h
#define _ROS_SERVICE_get_al_dish_from_rack_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace loraine_tasks
{

static const char GET_AL_DISH_FROM_RACK[] = "loraine_tasks/get_al_dish_from_rack";

  class get_al_dish_from_rackRequest : public ros::Msg
  {
    public:
      typedef int32_t _pickup_rack_num_type;
      _pickup_rack_num_type pickup_rack_num;

    get_al_dish_from_rackRequest():
      pickup_rack_num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_pickup_rack_num;
      u_pickup_rack_num.real = this->pickup_rack_num;
      *(outbuffer + offset + 0) = (u_pickup_rack_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pickup_rack_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pickup_rack_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pickup_rack_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pickup_rack_num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_pickup_rack_num;
      u_pickup_rack_num.base = 0;
      u_pickup_rack_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pickup_rack_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pickup_rack_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pickup_rack_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pickup_rack_num = u_pickup_rack_num.real;
      offset += sizeof(this->pickup_rack_num);
     return offset;
    }

    const char * getType(){ return GET_AL_DISH_FROM_RACK; };
    const char * getMD5(){ return "0293316b8ec2b14822bb7881a2abec41"; };

  };

  class get_al_dish_from_rackResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    get_al_dish_from_rackResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return GET_AL_DISH_FROM_RACK; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class get_al_dish_from_rack {
    public:
    typedef get_al_dish_from_rackRequest Request;
    typedef get_al_dish_from_rackResponse Response;
  };

}
#endif
