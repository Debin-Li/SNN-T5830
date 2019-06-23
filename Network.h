//
// Created by Yilong Guo on 2019-06-20.
//

#ifndef SNN_T5830_NETWORK_H
#define SNN_T5830_NETWORK_H

#include "DataLoader.h"

#define RESULTS_LOC "/Users/Nuullll/Projects/SNN-T5830/results/"

// Pattern/background phase
#define PATTERN_TIME 200
#define BACKGROUND_TIME 3
#define PATTERN_RATE 1.0
#define BACKGROUND_RATE 7.0

// Tracker for LIF threshold adaptation
#define TRACKER_SIZE 1000

#define LIF_THRESHOLD_REST 0.4
#define LIF_TAU 200
#define LIF_ADAPT_FACTOR 1.1

enum {PATTERN, BACKGROUND};
enum {TRAIN, TEST};


extern long InputSpikes[INPUT_SIZE];
extern long OutputSpikes[OUTPUT_SIZE];
extern double Weights[INPUT_SIZE][OUTPUT_SIZE];


extern void StartTrain();
extern void GetTrainInstruction(void* end_of_train);
extern void GetTrainFeedbackInstruction(int* currents);

extern void StartTest();
extern void GetTestInstruction();
extern void GetTestFeedbackInstruction(int* currents, void* end_of_test);

// Save/load model
extern void Save();
extern void SaveThresholds(const char* path);
extern void LoadThresholds(const char* path);
extern void SaveWeights(const char* path);
extern void LoadWeights(const char* path);
extern void SaveConfig(const char* path);
extern void SaveLabels(const char* path);
extern void SaveResponses(const char* path);

// private functions
static int FetchTrainImage(int index);
static int FireInputSpikes();
static void LeakOutputMembranes();
static void FireOutputSpikes();
static void TrackAndAdapt();
static int FetchTestImage(int index);


#endif //SNN_T5830_NETWORK_H
