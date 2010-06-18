/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#pragma once

#include "OgreDistanceLodStrategy.h"
#include "MogreLodStrategy.h"
#include "MogrePrerequisites.h"
#include "MogreMesh.h"
#include "MogreMaterial.h"

namespace Mogre
{
	//################################################################
	//DistanceLodStrategy
	//################################################################
	
	public ref class DistanceLodStrategy : public LodStrategy
	{
		//Nested Types
	
		//Private Declarations
	private protected:
		static DistanceLodStrategy^ _singleton;
	
		//Internal Declarations
	public protected:
		DistanceLodStrategy( Ogre::DistanceLodStrategy* obj ) : LodStrategy(obj)
		{
		}
	
	
		//Public Declarations
	public:
		DistanceLodStrategy( );
	
		static property DistanceLodStrategy^ Singleton
		{
			DistanceLodStrategy^ get()
			{
				Ogre::DistanceLodStrategy* ptr = Ogre::DistanceLodStrategy::getSingletonPtr();
				if (_singleton == CLR_NULL || _singleton->_native != ptr)
				{
					if (_singleton != CLR_NULL)
					{
						_singleton->_native = 0;
						_singleton = nullptr;
					}
					if ( ptr ) _singleton = gcnew DistanceLodStrategy( ptr );
				}
				return _singleton;
			}
		}
	
		property Mogre::Real BaseValue
		{
		public:
			Mogre::Real get();
		}
	
		property bool ReferenceViewEnabled
		{
		public:
			bool get();
		public:
			void set(bool value);
		}
	
		void _Init_CLRObject( );
	
		Mogre::Real TransformBias( Mogre::Real factor );
	
		Mogre::Real TransformUserValue( Mogre::Real userValue );
	
		Mogre::ushort GetIndex( Mogre::Real value, Mogre::Mesh::Const_MeshLodUsageList^ meshLodUsageList );
	
		Mogre::ushort GetIndex( Mogre::Real value, Mogre::Material::Const_LodValueList^ materialLodValueList );
	
		void Sort( Mogre::Mesh::MeshLodUsageList^ meshLodUsageList );
	
		bool IsSorted( Mogre::Mesh::Const_LodValueList^ values );
	
		void SetReferenceView( Mogre::Real viewportWidth, Mogre::Real viewportHeight, Mogre::Radian fovY );
	
	
		//Protected Declarations
	protected public:
	
	};
	

}
