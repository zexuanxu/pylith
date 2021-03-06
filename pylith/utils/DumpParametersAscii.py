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
# Copyright (c) 2010-2017 University of California, Davis
#
# See COPYING for license information.
#
# ----------------------------------------------------------------------
#

# @file pylith/utils/DumpParametersAscii.py
##
# @brief Python DumpParameters object for dumping PyLith parameter information to an ASCII file.

from .DumpParameters import DumpParameters

# DumpParameters class


class DumpParametersAscii(DumpParameters):
    """
    Python DumpParameters object for dumping PyLith parameter information to an ASCII file.
    """

    # INVENTORY //////////////////////////////////////////////////////////

    class Inventory(DumpParameters.Inventory):
        """
        Python object for managing DumpParametersAscii facilities and properties.
        """

        # @class Inventory
        # Python object for managing DumpParametersAscii facilities and properties.
        #
        # \b Properties
        # @li \b filename Name of file written with parameters.
        # @li \b indent Number of spaces to indent.
        # @li \b verbose Include description, location, and aliases.
        #
        # \b Facilities
        # @li None

        import pyre.inventory

        filename = pyre.inventory.str("filename", default="pylith_paramters.txt")
        filename.meta["tip"] = "Name of file written with parameters."

        indent = pyre.inventory.int("indent", default=4)
        indent.meta["tip"] = "Nmber of spaces to indent."

        verbose = pyre.inventory.bool("verbose", default=True)
        verbose.meta["tip"] = "Include description, location, and aliases."

    # PUBLIC METHODS /////////////////////////////////////////////////////

    def __init__(self, name="dumpparametersascii"):
        """
        Constructor.
        """
        DumpParameters.__init__(self, name)
        return

    def write(self, app):
        """
        Write parameters to ASCII file.
        """
        if self.info is None:
            self.collect(app)

        parameters = self.info["application"]
        with open(self.filename, "w") as fout:
            from .CollectVersionInfo import CollectVersionInfo
            import datetime
            now = datetime.datetime.now()
            fout.write("Generated %s\n\n" % now.strftime("%A, %d %B %Y %I:%M%p"))
            fout.write(CollectVersionInfo.asString())
            fout.write("\nApplication: %(name)s %(class)s\n" % parameters)
            depth = 0
            self._writeComponent(fout, parameters, depth + 1)
        return

    # PRIVATE METHODS ////////////////////////////////////////////////////

    def _configure(self):
        """
        Configure object.
        """
        DumpParameters._configure(self)
        self.filename = self.inventory.filename
        self.indent = self.inventory.indent
        self.verbose = self.inventory.verbose
        self.tab = " " * self.indent
        return

    def _writeComponent(self, fout, obj, depth):
        """
        Write component parameters to file.
        """
        indent = self.tab * depth
        for (key, item) in obj["properties"].items():
            if self.verbose:
                fout.write("\n")
            fout.write("%s%s (%s) = %s\n" % (indent, key, item["type"], item["value"]))
            if self.verbose:
                indent2 = indent + self.tab
                fout.write("%sDescription: %s\n" % (indent2, item["description"]))
                fout.write("%sSet from: %s\n" % (indent2, item["setFrom"]))

        for (key, item) in obj["components"].items():
            fout.write("\n%s%s = %s (%s)\n" % (indent, key, item["name"], item["class"]))
            if self.verbose:
                indent2 = indent + self.tab
                fout.write("%sConfigurable as: %s\n" % (indent2, ", ".join(item["aliases"])))
                fout.write("%sDescription: %s\n" % (indent2, item["description"]))
                fout.write("%sSet from: %s\n" % (indent2, item["setFrom"]))

            self._writeComponent(fout, item, depth + 1)
        return

# FACTORIES ////////////////////////////////////////////////////////////


def dump_parameters():
    """
    Factory associated with DumpParametersAscii.
    """
    return DumpParametersAscii()

# End of file
