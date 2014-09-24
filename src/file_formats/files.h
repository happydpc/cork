// +-------------------------------------------------------------------------
// | files.h
// | 
// | Author: Gilbert Bernstein
// +-------------------------------------------------------------------------
// | COPYRIGHT:
// |    Copyright Gilbert Bernstein 2013
// |    See the included COPYRIGHT file for further details.
// |    
// |    This file is part of the Cork library.
// |
// |    Cork is free software: you can redistribute it and/or modify
// |    it under the terms of the GNU Lesser General Public License as
// |    published by the Free Software Foundation, either version 3 of
// |    the License, or (at your option) any later version.
// |
// |    Cork is distributed in the hope that it will be useful,
// |    but WITHOUT ANY WARRANTY; without even the implied warranty of
// |    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |    GNU Lesser General Public License for more details.
// |
// |    You should have received a copy 
// |    of the GNU Lesser General Public License
// |    along with Cork.  If not, see <http://www.gnu.org/licenses/>.
// +-------------------------------------------------------------------------
#pragma once

#include <string>

//#include "triMesh.h"

#include "../rawmesh/rawMesh.h"

/*
 *  Files provides a wrapper for different file types and a common
 *  data view for the rest of the program.  This wrapper was introduced
 *  to make it easier to support multiple file types using other people's
 *  file importer/exporter code
 */
#if defined(_WINDLL)
#define CORK_IMP_EXP __declspec(dllexport)
#elif defined(CORK_STATIC)
#define CORK_IMP_EXP
#else
#define CORK_IMP_EXP __declspec(dllimport)
#endif

namespace Files {

// all functions with integer return values here are intended
// to return an error count as if they were a main function

struct FileVertex : public MinimalVertexData {};
struct FileTriangle : public MinimalTriangleData {};
typedef RawMesh<FileVertex,FileTriangle> FileMesh;
//using FileMesh = RawMesh<FileVertex, FileTriangle>;

// generic filetype functions
// these detect which filetype to use by inspecting the filename
CORK_IMP_EXP int readTriMesh(std::string filename, FileMesh *mesh);
CORK_IMP_EXP int writeTriMesh(std::string filename, FileMesh *mesh);

// specific filetype functions
CORK_IMP_EXP int readIFS(std::string filename, FileMesh *mesh);
CORK_IMP_EXP int writeIFS(std::string filename, FileMesh *mesh);

CORK_IMP_EXP int readOFF(std::string filename, FileMesh *mesh);
CORK_IMP_EXP int writeOFF(std::string filename, FileMesh *mesh);

} // end namespace Files