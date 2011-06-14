#!/usr/bin/env python
#
# ----------------------------------------------------------------------
#
# Brad T. Aagaard, U.S. Geological Survey
# Charles A. Williams, GNS Science
# Matthew G. Knepley, University of Chicago
#
# This code was developed as part of the Computational Infrastructure
# for Geodynamics (http://geodynamics.org).
#
# Copyright (c) 2010-2011 University of California, Davis
#
# See COPYING for license information.
#
# ----------------------------------------------------------------------
#

## @file tests/2d/tri3/TestShearDisp.py
##
## @brief Test suite for testing pylith with 2-D shear.

import numpy
from TestTri3 import TestTri3
from sheardisp_soln import AnalyticalSoln
from pylith.utils.VTKDataReader import has_vtk
from pylith.utils.VTKDataReader import VTKDataReader

# Local version of PyLithApp
from pylith.apps.PyLithApp import PyLithApp
class ShearApp(PyLithApp):
  def __init__(self):
    PyLithApp.__init__(self, name="sheardisp")
    return


# Helper function to run PyLith
def run_pylith():
  """
  Run pylith.
  """
  if not "done" in dir(run_pylith):
    # Generate spatial databases
    from sheardisp_gendb import GenerateDB
    db = GenerateDB()
    db.run()

    # Run PyLith
    app = ShearApp()
    app.run()
    run_pylith.done = True
  return


class TestShearDisp(TestTri3):
  """
  Test suite for testing pylith with 2-D shear extension.
  """

  def setUp(self):
    """
    Setup for test.
    """
    TestTri3.setUp(self)
    run_pylith()
    self.outputRoot = "sheardisp"
    if has_vtk():
      self.reader = VTKDataReader()
      self.soln = AnalyticalSoln()
    else:
      self.reader = None
    return


  def calcDisplacements(self, vertices):
    """
    Calculate displacement field given coordinates of vertices.
    """
    return self.soln.displacement(vertices)


  def calcStateVar(self, name, vertices, cells):
    """
    Calculate state variable.
    """
    ncells = self.mesh['ncells']
    pts = numpy.zeros( (ncells, 3), dtype=numpy.float64)
    if name == "total_strain":
      stateVar = self.soln.strain(pts)
    elif name == "stress":
      stateVar = self.soln.stress(pts)
    else:
      raise ValueError("Unknown state variable '%s'." % name)

    return stateVar


# End of file 
