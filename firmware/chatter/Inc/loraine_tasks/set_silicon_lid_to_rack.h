#ifndef _ROS_SERVICE_set_silicon_lid_to_rack_h
#define _ROS_SERVICE_set_silicon_lid_to_rack_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace loraine_tasks
{

static const char SET_SILICON_LID_TO_RACK[] = "loraine_tasks/set_silicon_lid_to_rack";

  class set_silicon_lid_to_rackRequest : public ros::Msg
  {
    public:
      typedef int32_t _lid_num_type;
      _lid_num_type lid_num;

    set_silicon_lid_to_rackRequest():
      lid_num(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_lid_num;
      u_lid_num.real = this->lid_num;
      *(outbuffer + offset + 0) = (u_lid_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lid_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lid_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lid_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lid_num);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_lid_num;
      u_lid_num.base = 0;
      u_lid_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_lid_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_lid_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_lid_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->lid_num = u_lid_num.real;
      offset += sizeof(this->lid_num);
     return offset;
    }

    const char * getType(){ return SET_SILICON_LID_TO_RACK; };
    const char * getMD5(){ return "0cad7ce1e074c104e12f4c514f753a53"; };

  };

  class set_silicon_lid_to_rackResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    set_silicon_lid_to_rackResponse():
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

    const char * getType(){ return SET_SILICON_LID_TO_RACK; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class set_silicon_lid_to_rack {
    public:
    typedef set_silicon_lid_to_rackRequest Request;
    typedef set_silicon_lid_to_rackResponse Response;
  };

}
#endif
