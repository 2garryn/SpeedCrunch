/* This file is part of the SpeedCrunch project
   Copyright (C) 2004 Ariya Hidayat <ariya@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */


#ifndef FUNCTIONS
#define FUNCTIONS

#include <QStringList>
#include <QVector>
#include "hmath.h"

class Function;
class Evaluator;

class FunctionPrivate;
class FunctionRepositoryPrivate;

typedef QVector<HNumber> FunctionArguments;
typedef HNumber (*FunctionPtr)( const Evaluator*, Function*, const FunctionArguments& );

class Function
{
public:
  Function( const QString& name, int argc, FunctionPtr ptr, const QString& desc );
  Function( const QString& name, FunctionPtr ptr, const QString& desc );
  ~Function();
  QString name() const;
  QString description() const;
  QString error() const;
  void setError( const QString& );
  HNumber exec( const Evaluator*, const FunctionArguments& args );

private:
  FunctionPrivate* d;
  Function( const Function& );
  Function& operator=( const Function& );
};

class FunctionRepository
{
public:
  FunctionRepository();
  ~FunctionRepository();
  static FunctionRepository* self();
  void add( Function* function );
  Function* function( const QString& name );
  QStringList functionNames() const;
private:
  FunctionRepositoryPrivate* d;
  static FunctionRepository* s_self;
  FunctionRepository( const FunctionRepository& );
  FunctionRepository& operator=( const FunctionRepository& );
};


#endif // FUNCTIONS