/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#pragma once

#include "OgrePixelCountLodStrategy.h"
#include "MogreLodStrategy.h"
#include "MogrePrerequisites.h"
#include "MogreMesh.h"
#include "MogreMaterial.h"

namespace Mogre
{
	//################################################################
	//PixelCountLodStrategy
	//################################################################
	
	public ref class PixelCountLodStrategy : public LodStrategy
	{
		//Nested Types
	
		//Private Declarations
	private protected:
		static PixelCountLodStrategy^ _singleton;
	
		//Internal Declarations
	public protected:
		PixelCountLodStrategy( Ogre::PixelCountLodStrategy* obj ) : LodStrategy(obj)
		{
		}
	
	
		//Public Declarations
	public:
		PixelCountLodStrategy( );
	
		static property PixelCountLodStrategy^ Singleton
		{
			PixelCountLodStrategy^ get()
			{
				Ogre::PixelCountLodStrategy* ptr = Ogre::PixelCountLodStrategy::getSingletonPtr();
				if (_singleton == CLR_NULL || _singleton->_native != ptr)
				{
					if (_singleton != CLR_NULL)
					{
						_singleton->_native = 0;
						_singleton = nullptr;
					}
					if ( ptr ) _singleton = gcnew PixelCountLodStrategy( ptr );
				}
				return _singleton;
			}
		}
	
		property Mogre::Real BaseValue
		{
		public:
			Mogre::Real get();
		}
	
		void _Init_CLRObject( );
	
		Mogre::Real TransformBias( Mogre::Real factor );
	
		Mogre::ushort GetIndex( Mogre::Real value, Mogre::Mesh::Const_MeshLodUsageList^ meshLodUsageList );
	
		Mogre::ushort GetIndex( Mogre::Real value, Mogre::Material::Const_LodValueList^ materialLodValueList );
	
		void Sort( Mogre::Mesh::MeshLodUsageList^ meshLodUsageList );
	
		bool IsSorted( Mogre::Mesh::Const_LodValueList^ values );
	
	
		//Protected Declarations
	protected public:
	
	};
	

}
