// -*- C++ -*-
//
// ----------------------------------------------------------------------
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
// ----------------------------------------------------------------------
//

#include <portinfo>

#include "TestGeometryTri2D.hh" // Implementation of class methods

#include "pylith/feassemble/GeometryTri2D.hh"
#include "pylith/feassemble/GeometryLine2D.hh"
#include "pylith/feassemble/GeometryPoint2D.hh"

#include "data/GeomDataTri2D.hh"

// ----------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( pylith::feassemble::TestGeometryTri2D );

// ----------------------------------------------------------------------
// Setup test data.
void
pylith::feassemble::TestGeometryTri2D::setUp(void)
{ // setUp
  _object = new GeometryTri2D();
  _data = new GeomDataTri2D();
} // setUp

// ----------------------------------------------------------------------
// Test constructor
void
pylith::feassemble::TestGeometryTri2D::testConstructor(void)
{ // testConstructor
  GeometryTri2D geometry;
} // testConstructor

// ----------------------------------------------------------------------
// Test geometryLowerDim().
void
pylith::feassemble::TestGeometryTri2D::testGeomLowerDim(void)
{ // testGeomLowerDim
  GeometryTri2D geometry;
  CellGeometry* geometryLD = geometry.geometryLowerDim();
  GeometryLine2D* geometryPt = dynamic_cast<GeometryLine2D*>(geometryLD);
  CPPUNIT_ASSERT(0 != geometryPt);
  GeometryPoint2D* geometryPt2 = dynamic_cast<GeometryPoint2D*>(geometryLD);
  CPPUNIT_ASSERT(0 == geometryPt2);
  delete geometryLD; geometryLD = 0;
} // testGeomLowerDim


// End of file 
