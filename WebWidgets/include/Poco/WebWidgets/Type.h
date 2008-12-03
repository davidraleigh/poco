//
// Type.h
//
// $Id: //poco/Main/WebWidgets/include/Poco/WebWidgets/Type.h#3 $
//
// Library: WebWidgets
// Package: Core
// Module:  Type
//
// Definition of the Type class.
//
// Copyright (c) 2008, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef WebWidgets_Type_INCLUDED
#define WebWidgets_Type_INCLUDED


#include "Poco/WebWidgets/WebWidgets.h"
#include <typeinfo>


namespace Poco {
namespace WebWidgets {


class WebWidgets_API Type
	/// A wrapper for std::type_info that exposes value semantics.
	///
	/// This class is useful as a key in a std::map or std::set.
{
public:
	Type();
		/// Creates a Type for void.
		
	Type(const std::type_info& type);
		/// Creates a Type from the given std::type_info.
				
	~Type();
		/// Destroys the Type.
		
	void swap(Type& type);
		/// Swaps the Type with another one.
		
	Type& operator = (const Type& type);
		/// Assignment operator.
		
	Type& operator = (const std::type_info& type);
		/// Assignment operator.
		
	const std::type_info& type() const;
		/// Returns the underlying std::type_info object.
		
	bool operator == (const Type& type) const;
	bool operator != (const Type& type) const;
	bool operator < (const Type& type) const;
		
private:
	const std::type_info* _pType;
};


//
// inlines
//
inline const std::type_info& Type::type() const
{
	return *_pType;
}


inline bool Type::operator == (const Type& type) const
{
	return *_pType == *type._pType;
}


inline bool Type::operator != (const Type& type) const
{
	return *_pType != *type._pType;
}


inline bool Type::operator < (const Type& type) const
{
	return _pType->before(*type._pType) != 0;
}


} } // namespace Poco::WebWidgets


#endif // WebWidgets_Type_INCLUDED