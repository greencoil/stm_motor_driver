#ifndef _ROS_SERVICE_set_al_dish_to_tray_h
#define _ROS_SERVICE_set_al_dish_to_tray_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace loraine_tasks
{

static const char SET_AL_DISH_TO_TRAY[] = "loraine_tasks/set_al_dish_to_tray";

  class set_al_dish_to_trayRequest : public ros::Msg
  {
    public:
      typedef int32_t _food_num_type;
      _food_num_type food_num;

    set_al_dish_to_trayRequest():
      food_num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_food_num;
      u_food_num.real = this->food_num;
      *(outbuffer + offset + 0) = (u_food_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_food_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_food_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_food_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->food_num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_food_num;
      u_food_num.base = 0;
      u_food_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_food_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_food_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_food_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->food_num = u_food_num.real;
      offset += sizeof(this->food_num);
     return offset;
    }

    const char * getType(){ return SET_AL_DISH_TO_TRAY; };
    const char * getMD5(){ return "28e3149ff91e7d9a7e5881d474faa7cd"; };

  };

  class set_al_dish_to_trayResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    set_al_dish_to_trayResponse():
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

    const char * getType(){ return SET_AL_DISH_TO_TRAY; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class set_al_dish_to_tray {
    public:
    typedef set_al_dish_to_trayRequest Request;
    typedef set_al_dish_to_trayResponse Response;
  };

}
#endif
