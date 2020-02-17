#ifndef _ROS_standard_cpp_templates_Move_h
#define _ROS_standard_cpp_templates_Move_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace standard_cpp_templates
{

  class Move : public ros::Msg
  {
    public:
      typedef const char* _moveType_type;
      _moveType_type moveType;
      double pose1[6];
      double pose2[6];
      typedef uint32_t _acc_type;
      _acc_type acc;
      typedef uint32_t _speed_type;
      _speed_type speed;
      typedef uint32_t _blend_type;
      _blend_type blend;

    Move():
      moveType(""),
      pose1(),
      pose2(),
      acc(0),
      speed(0),
      blend(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_moveType = strlen(this->moveType);
      varToArr(outbuffer + offset, length_moveType);
      offset += 4;
      memcpy(outbuffer + offset, this->moveType, length_moveType);
      offset += length_moveType;
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_pose1i;
      u_pose1i.real = this->pose1[i];
      *(outbuffer + offset + 0) = (u_pose1i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pose1i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pose1i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pose1i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pose1i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pose1i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pose1i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pose1i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pose1[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_pose2i;
      u_pose2i.real = this->pose2[i];
      *(outbuffer + offset + 0) = (u_pose2i.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pose2i.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pose2i.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pose2i.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_pose2i.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_pose2i.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_pose2i.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_pose2i.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->pose2[i]);
      }
      *(outbuffer + offset + 0) = (this->acc >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->acc >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->acc >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->acc >> (8 * 3)) & 0xFF;
      offset += sizeof(this->acc);
      *(outbuffer + offset + 0) = (this->speed >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->speed >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->speed >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->speed >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      *(outbuffer + offset + 0) = (this->blend >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->blend >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->blend >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->blend >> (8 * 3)) & 0xFF;
      offset += sizeof(this->blend);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_moveType;
      arrToVar(length_moveType, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_moveType; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_moveType-1]=0;
      this->moveType = (char *)(inbuffer + offset-1);
      offset += length_moveType;
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_pose1i;
      u_pose1i.base = 0;
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pose1i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pose1[i] = u_pose1i.real;
      offset += sizeof(this->pose1[i]);
      }
      for( uint32_t i = 0; i < 6; i++){
      union {
        double real;
        uint64_t base;
      } u_pose2i;
      u_pose2i.base = 0;
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_pose2i.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->pose2[i] = u_pose2i.real;
      offset += sizeof(this->pose2[i]);
      }
      this->acc =  ((uint32_t) (*(inbuffer + offset)));
      this->acc |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->acc |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->acc |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->acc);
      this->speed =  ((uint32_t) (*(inbuffer + offset)));
      this->speed |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->speed |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->speed |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->speed);
      this->blend =  ((uint32_t) (*(inbuffer + offset)));
      this->blend |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->blend |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->blend |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->blend);
     return offset;
    }

    const char * getType(){ return "standard_cpp_templates/Move"; };
    const char * getMD5(){ return "d17e0c9b9da6738ff41ac126d78cd367"; };

  };

}
#endif
