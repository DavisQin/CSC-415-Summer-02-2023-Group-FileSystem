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
* File: VCB.h
*
* Description:
*
**************************************************************/

typedef struct VolumeControlBlock{
    unsigned int signature;
	unsigned int blockSize;
	unsigned int totalBlocks;
	int freeBlocks;//??
}VCB;