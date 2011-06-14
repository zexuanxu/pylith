// -*- C++ -*-
//
// ======================================================================
//
// Brad T. Aagaard, U.S. Geological Survey
// Charles A. Williams, GNS Science
// Matthew G. Knepley, University of Chicago
//
// This code was developed as part of the Computational Infrastructure
// for Geodynamics (http://geodynamics.org).
//
// Copyright (c) 2010-2011 University of California, Davis
//
// See COPYING for license information.
//
// ======================================================================
//

// DO NOT EDIT THIS FILE
// This file was generated from python application quadratureapp.

#include "QuadratureData3DLinear.hh"

const int pylith::feassemble::QuadratureData3DLinear::_numVertices = 4;

const int pylith::feassemble::QuadratureData3DLinear::_spaceDim = 3;

const int pylith::feassemble::QuadratureData3DLinear::_numCells = 1;

const int pylith::feassemble::QuadratureData3DLinear::_cellDim = 3;

const int pylith::feassemble::QuadratureData3DLinear::_numBasis = 4;

const int pylith::feassemble::QuadratureData3DLinear::_numQuadPts = 1;

const double pylith::feassemble::QuadratureData3DLinear::_vertices[] = {
 -5.00000000e-01, -1.00000000e+00, -5.00000000e-01,
  2.00000000e+00, -5.00000000e-01, -4.00000000e-01,
  1.00000000e+00, -1.00000000e-01, -3.00000000e-01,
 -2.00000000e-01,  5.00000000e-01,  2.00000000e+00,
};

const int pylith::feassemble::QuadratureData3DLinear::_cells[] = {
       0,       1,       2,       3,
};

const double pylith::feassemble::QuadratureData3DLinear::_verticesRef[] = {
 -1.00000000e+00, -1.00000000e+00, -1.00000000e+00,
  1.00000000e+00, -1.00000000e+00, -1.00000000e+00,
 -1.00000000e+00,  1.00000000e+00, -1.00000000e+00,
 -1.00000000e+00, -1.00000000e+00,  1.00000000e+00,
};

const double pylith::feassemble::QuadratureData3DLinear::_quadPtsRef[] = {
 -5.00000000e-01, -5.00000000e-01, -5.00000000e-01,
};

const double pylith::feassemble::QuadratureData3DLinear::_quadWts[] = {
  1.33333333e+00,
};

const double pylith::feassemble::QuadratureData3DLinear::_quadPts[] = {
  5.75000000e-01, -2.75000000e-01,  2.00000000e-01,
};

const double pylith::feassemble::QuadratureData3DLinear::_basis[] = {
  2.50000000e-01,  2.50000000e-01,  2.50000000e-01,
  2.50000000e-01,};

const double pylith::feassemble::QuadratureData3DLinear::_basisDerivRef[] = {
 -5.00000000e-01, -5.00000000e-01, -5.00000000e-01,
  5.00000000e-01,  0.00000000e+00,  0.00000000e+00,
  0.00000000e+00,  5.00000000e-01,  0.00000000e+00,
  0.00000000e+00,  0.00000000e+00,  5.00000000e-01,
};

const double pylith::feassemble::QuadratureData3DLinear::_basisDeriv[] = {
 -2.66418835e-01, -6.75340768e-01,  3.71747212e-02,
  6.04089219e-01, -1.14312268e+00,  6.13382900e-01,
 -3.40768278e-01,  1.92688971e+00, -1.11524164e+00,
  3.09789343e-03, -1.08426270e-01,  4.64684015e-01,
};

const double pylith::feassemble::QuadratureData3DLinear::_jacobian[] = {
  1.25000000e+00,  7.50000000e-01,  1.50000000e-01,
  2.50000000e-01,  4.50000000e-01,  7.50000000e-01,
  5.00000000e-02,  1.00000000e-01,  1.25000000e+00,
};

const double pylith::feassemble::QuadratureData3DLinear::_jacobianDet[] = {
  4.03500000e-01,
};

const double pylith::feassemble::QuadratureData3DLinear::_jacobianInv[] = {
  1.20817844e+00, -2.28624535e+00,  1.22676580e+00,
 -6.81536555e-01,  3.85377943e+00, -2.23048327e+00,
  6.19578686e-03, -2.16852540e-01,  9.29368030e-01,
};

pylith::feassemble::QuadratureData3DLinear::QuadratureData3DLinear(void)
{ // constructor
  numVertices = _numVertices;
  spaceDim = _spaceDim;
  numCells = _numCells;
  cellDim = _cellDim;
  numBasis = _numBasis;
  numQuadPts = _numQuadPts;
  vertices = const_cast<double*>(_vertices);
  cells = const_cast<int*>(_cells);
  verticesRef = const_cast<double*>(_verticesRef);
  quadPtsRef = const_cast<double*>(_quadPtsRef);
  quadWts = const_cast<double*>(_quadWts);
  quadPts = const_cast<double*>(_quadPts);
  basis = const_cast<double*>(_basis);
  basisDerivRef = const_cast<double*>(_basisDerivRef);
  basisDeriv = const_cast<double*>(_basisDeriv);
  jacobian = const_cast<double*>(_jacobian);
  jacobianDet = const_cast<double*>(_jacobianDet);
  jacobianInv = const_cast<double*>(_jacobianInv);
} // constructor

pylith::feassemble::QuadratureData3DLinear::~QuadratureData3DLinear(void)
{}


// End of file
