using System;
using System.Collections.Generic;
using System.Text;

namespace FSLOgreCS
{
    public class FSLAmbientSound : FSLSoundObject
    {
        public FSLAmbientSound( string soundFile, string name, bool loop,bool streaming ) 
            : base( soundFile, name, loop, streaming )
        {
	        FreeSL.fslSoundSetSourceRelative( _sound, true);
        }
        public FSLAmbientSound(string package, string soundFile, string name, bool loop)
            : base(package, soundFile, name, loop)
        {
            FreeSL.fslSoundSetSourceRelative(_sound, true);
        }
        public override void Update(){
        }
    }
}
