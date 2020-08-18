#include "config.h"
#include "pokeysnd.h"
#include "mzpokeysnd.h"
#include "sndsave.h"

void Pokey_sound_init(uint32 freq17, uint16 playback_freq, uint8 num_pokeys)
{
	Pokey_sound_init_rf(freq17,playback_freq, num_pokeys);
	Pokey_sound_init_mz(freq17,playback_freq, num_pokeys,0,0);
}
void Update_pokey_sound(uint16 addr, uint8 val, uint8 chip, uint8 gain)
{
	if (enable_new_pokey)
		Update_pokey_sound_mz(addr,val,chip,gain);
	else
		Update_pokey_sound_rf(addr,val,chip,gain);
}
void Pokey_process(uint16 * sndbuffer, const uint16 sndn)
{
	if (enable_new_pokey)
		Pokey_process_16(sndbuffer, sndn);
	else
		Pokey_process_rf(sndbuffer,sndn);

/*	char * buffer = sndbuffer;
	int i;
	for (i=0; i<sndn; ++i)
		fprintf(stderr, "Q:%d\n", buffer[i]);
*/
        if( IsSoundFileOpen())
                WriteToSoundFile(sndbuffer, sndn);
}
#ifdef SERIO_SOUND
void Update_serio_sound( int out, UBYTE data )
{
	if (enable_new_pokey)
		Update_serio_sound_mz(out,data);
	else
		Update_serio_sound_rf(out,data);
}
#endif
#ifdef CONSOLE_SOUND
void Update_consol_sound( int set )
{
	if (enable_new_pokey)
		Update_consol_sound_mz(set);
	else
		Update_consol_sound_rf(set);
}
#endif
#ifdef VOL_ONLY_SOUND
void Update_vol_only_sound( void )
{
	if (enable_new_pokey)
		Update_vol_only_sound_mz();
	else
		Update_vol_only_sound_rf();
}
#endif
	
