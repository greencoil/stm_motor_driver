#ifndef _ROS_SERVICE_set_al_dish_to_hotplate_h
#define _ROS_SERVICE_set_al_dish_to_hotplate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace loraine_tasks
{

static const char SET_AL_DISH_TO_HOTPLATE[] = "loraine_tasks/set_al_dish_to_hotplate";

  class set_al_dish_to_hotplateRequest : public ros::Msg
  {
    public:
      typedef int32_t _hotplate_num_type;
      _hotplate_num_type hotplate_num;

    set_al_dish_to_hotplateRequest():
      hotplate_num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_hotplate_num;
      u_hotplate_num.real = this->hotplate_num;
      *(outbuffer + offset + 0) = (u_hotplate_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_hotplate_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_hotplate_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_hotplate_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hotplate_num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_hotplate_num;
      u_hotplate_num.base = 0;
      u_hotplate_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_hotplate_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_hotplate_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_hotplate_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->hotplate_num = u_hotplate_num.real;
      offset += sizeof(this->hotplate_num);
     return offset;
    }

    const char * getType(){ return SET_AL_DISH_TO_HOTPLATE; };
    const char * getMD5(){ return "63e11edfae010770fdf1a26967083e41"; };

  };

  class set_al_dish_to_hotplateResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    set_al_dish_to_hotplateResponse():
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

    const char * getType(){ return SET_AL_DISH_TO_HOTPLATE; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class set_al_dish_to_hotplate {
    public:
    typedef set_al_dish_to_hotplateRequest Request;
    typedef set_al_dish_to_hotplateResponse Response;
  };

}
#endif
