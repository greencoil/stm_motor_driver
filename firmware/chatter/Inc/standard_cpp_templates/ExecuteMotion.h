#ifndef _ROS_SERVICE_ExecuteMotion_h
#define _ROS_SERVICE_ExecuteMotion_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "standard_cpp_templates/Move.h"

namespace standard_cpp_templates
{

static const char EXECUTEMOTION[] = "standard_cpp_templates/ExecuteMotion";

  class ExecuteMotionRequest : public ros::Msg
  {
    public:
      uint32_t moveList_length;
      typedef standard_cpp_templates::Move _moveList_type;
      _moveList_type st_moveList;
      _moveList_type * moveList;

    ExecuteMotionRequest():
      moveList_length(0), moveList(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->moveList_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->moveList_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->moveList_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->moveList_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->moveList_length);
      for( uint32_t i = 0; i < moveList_length; i++){
      offset += this->moveList[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t moveList_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      moveList_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      moveList_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      moveList_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->moveList_length);
      if(moveList_lengthT > moveList_length)
        this->moveList = (standard_cpp_templates::Move*)realloc(this->moveList, moveList_lengthT * sizeof(standard_cpp_templates::Move));
      moveList_length = moveList_lengthT;
      for( uint32_t i = 0; i < moveList_length; i++){
      offset += this->st_moveList.deserialize(inbuffer + offset);
        memcpy( &(this->moveList[i]), &(this->st_moveList), sizeof(standard_cpp_templates::Move));
      }
     return offset;
    }

    const char * getType(){ return EXECUTEMOTION; };
    const char * getMD5(){ return "1ea77ba39df25b7084dfcf73b7369408"; };

  };

  class ExecuteMotionResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    ExecuteMotionResponse():
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

    const char * getType(){ return EXECUTEMOTION; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class ExecuteMotion {
    public:
    typedef ExecuteMotionRequest Request;
    typedef ExecuteMotionResponse Response;
  };

}
#endif
