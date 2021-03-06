#ifndef _ROS_SERVICE_SetHOMECmd_h
#define _ROS_SERVICE_SetHOMECmd_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace dobot
{

static const char SETHOMECMD[] = "dobot/SetHOMECmd";

  class SetHOMECmdRequest : public ros::Msg
  {
    public:

    SetHOMECmdRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return SETHOMECMD; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetHOMECmdResponse : public ros::Msg
  {
    public:
      typedef int32_t _result_type;
      _result_type result;
      typedef uint64_t _queuedCmdIndex_type;
      _queuedCmdIndex_type queuedCmdIndex;

    SetHOMECmdResponse():
      result(0),
      queuedCmdIndex(0)
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
      *(outbuffer + offset + 0) = (this->queuedCmdIndex >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->queuedCmdIndex >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->queuedCmdIndex >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->queuedCmdIndex >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->queuedCmdIndex >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->queuedCmdIndex >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->queuedCmdIndex >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->queuedCmdIndex >> (8 * 7)) & 0xFF;
      offset += sizeof(this->queuedCmdIndex);
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
      this->queuedCmdIndex =  ((uint64_t) (*(inbuffer + offset)));
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->queuedCmdIndex |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->queuedCmdIndex);
     return offset;
    }

    const char * getType(){ return SETHOMECMD; };
    const char * getMD5(){ return "cbf7b461449133eb5dd6ebbd8d38dedc"; };

  };

  class SetHOMECmd {
    public:
    typedef SetHOMECmdRequest Request;
    typedef SetHOMECmdResponse Response;
  };

}
#endif
