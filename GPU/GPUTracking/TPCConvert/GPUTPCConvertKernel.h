// Copyright CERN and copyright holders of ALICE O2. This software is
// distributed under the terms of the GNU General Public License v3 (GPL
// Version 3), copied verbatim in the file "COPYING".
//
// See http://alice-o2.web.cern.ch/license for full licensing information.
//
// In applying this license CERN does not waive the privileges and immunities
// granted to it by virtue of its status as an Intergovernmental Organization
// or submit itself to any jurisdiction.

/// \file GPUTPCConvertKernel.h
/// \author David Rohr

#ifndef GPUTPCCONVERTKERNEL_H
#define GPUTPCCONVERTKERNEL_H

#include "GPUGeneralKernels.h"

namespace GPUCA_NAMESPACE
{
namespace gpu
{
class GPUTPCConvertKernel : public GPUKernelTemplate
{
 public:
  GPUhdi() static GPUDataTypes::RecoStep GetRecoStep() { return GPUDataTypes::RecoStep::TPCConversion; }
#if defined(GPUCA_BUILD_TPCCONVERT) && !defined(GPUCA_ALIROOT_LIB) && defined(HAVE_O2HEADERS)
  template <int iKernel = 0>
  GPUd() static void Thread(int nBlocks, int nThreads, int iBlock, int iThread, GPUsharedref() GPUTPCSharedMemory& smem, processorType& processors);
#endif
};
} // namespace gpu
} // namespace GPUCA_NAMESPACE

#endif
