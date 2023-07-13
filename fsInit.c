/**************************************************************
* Class:  CSC-415-02 Summer 2023
* Group Name: FileSystem
* Group member and ID: Davis Qin    921622218
*                      
*
*
*
* GitHub Repository:
* Project: File System
*
* File: VCB.c
*
* Description:
*
**************************************************************/

#include <stdio.h>


#define OUR_SIG 0x4F55524653 //"OURFS" in Hexademical

typedef struct Volumn_Control_Block {
    unsigned long sig; //our special signature
	unsigned long root_loc; //location of root directory
	unsigned long dir_size; //size of the directory
	unsigned long bitMap_size; //size of bitmap in blocks
	unsigned int block_size; //size each block will be blockSize
	unsigned int block_number; //number of blocks in the volume
	unsigned int bitMap_start; //block bitmap starts on
	unsigned int freeIndex; //marks what block to start looking for free space
}VCB;

//something
////something
//something
//something

