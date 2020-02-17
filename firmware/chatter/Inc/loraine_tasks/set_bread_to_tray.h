#ifndef _ROS_SERVICE_set_bread_to_tray_h
#define _ROS_SERVICE_set_bread_to_tray_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace loraine_tasks
{

static const char SET_BREAD_TO_TRAY[] = "loraine_tasks/set_bread_to_tray";

  class set_bread_to_trayRequest : public ros::Msg
  {
    public:
      typedef int32_t _bread_num_type;
      _bread_num_type bread_num;

    set_bread_to_trayRequest():
      bread_num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_bread_num;
      u_bread_num.real = this->bread_num;
      *(outbuffer + offset + 0) = (u_bread_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bread_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bread_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bread_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bread_num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_bread_num;
      u_bread_num.base = 0;
      u_bread_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bread_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bread_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bread_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bread_num = u_bread_num.real;
      offset += sizeof(this->bread_num);
     return offset;
    }

    const char * getType(){ return SET_BREAD_TO_TRAY; };
    const char * getMD5(){ return "e72a8d05011cf15c0258fdc732bdde93"; };

  };

  class set_bread_to_trayResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    set_bread_to_trayResponse():
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

    const char * getType(){ return SET_BREAD_TO_TRAY; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class set_bread_to_tray {
    public:
    typedef set_bread_to_trayRequest Request;
    typedef set_bread_to_trayResponse Response;
  };

}
#endif
