#ifndef ALIPHOSTRACKSEGMENTMAKER_H
#define ALIPHOSTRACKSEGMENTMAKER_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

/* $Id$ */

//_________________________________________________________________________
// Algorithm Base class to construct PHOS track segments
// Associates EMC and PPSD clusters
// Unfolds the EMC cluster   
//                  
//*-- Author: Dmitri Peressounko (RRC Ki & SUBATECH)

// --- ROOT system ---

// --- Standard library ---

// --- AliRoot header files ---

#include "TObjArray.h"
#include "AliPHOSClusterizer.h"
#include "AliPHOSEmcRecPoint.h"
#include "AliPHOSPpsdRecPoint.h"

typedef TObjArray TrackSegmentsList ;

class  AliPHOSTrackSegmentMaker : public TObject {

public:

  AliPHOSTrackSegmentMaker() ;                     
  
  virtual ~ AliPHOSTrackSegmentMaker(){}  // dtor

  virtual void MakeTrackSegments(DigitsList * DL, RecPointsList * emcl, RecPointsList * ppsdl, TrackSegmentsList * trsl ) = 0 ; 
                                         // does the job
  virtual void SetMaxEmcPpsdDistance(Float_t r) = 0 ; 
  virtual void SetUnfoldFlag() = 0 ;
  virtual void UnsetUnfoldFlag() = 0 ;

  ClassDef( AliPHOSTrackSegmentMaker,1)  // Algorithm class to make PHOS track segments (Base Class)

};

#endif // ALIPHOSTRACKSEGMENTMAKER_H
