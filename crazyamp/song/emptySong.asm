



emptySong_Start
emptySong_StartDisarkGenerateExternalLabel

emptySong_DisarkByteRegionStart0
	db "AT20"
emptySong_DisarkPointerRegionStart1
	dw emptySong_ArpeggioTable
	dw emptySong_PitchTable
	dw emptySong_InstrumentTable
	dw emptySong_EffectBlockTable
emptySong_DisarkPointerRegionEnd1



emptySong_DisarkPointerRegionStart2
	dw emptySong_Subsong0_Start
emptySong_DisarkPointerRegionEnd2


emptySong_ArpeggioTable
emptySong_DisarkPointerRegionStart3
emptySong_DisarkPointerRegionEnd3


emptySong_PitchTable
emptySong_DisarkPointerRegionStart4
emptySong_DisarkPointerRegionEnd4


emptySong_InstrumentTable
emptySong_DisarkPointerRegionStart5
	dw emptySong_EmptyInstrument
emptySong_DisarkPointerRegionEnd5

emptySong_EmptyInstrument
	db 0
emptySong_EmptyInstrument_Loop	db 0

	db 6



emptySong_EffectBlockTable
emptySong_DisarkPointerRegionStart6
	dw emptySong_EffectBlock_P4P1
emptySong_DisarkPointerRegionEnd6

emptySong_EffectBlock_P4P1
	db 4, 1

emptySong_DisarkByteRegionEnd0



emptySong_Subsong0_DisarkByteRegionStart0
emptySong_Subsong0_Start
	db 2
	db 0
	db 1
	db 0
	db 0
	db 6
	db 0

emptySong_Subsong0_Linker
emptySong_Subsong0_DisarkPointerRegionStart1

emptySong_Subsong0_Linker_Loop
	dw emptySong_Subsong0_Track0
	dw emptySong_Subsong0_Track0
	dw emptySong_Subsong0_Track1
	dw emptySong_Subsong0_LinkerBlock0

emptySong_Subsong0_DisarkPointerRegionEnd1
	dw 0
emptySong_Subsong0_DisarkWordForceReference2
	dw emptySong_Subsong0_Linker_Loop

emptySong_Subsong0_LinkerBlock0
	db 64
	db 0
	db 0
	db 0
emptySong_Subsong0_DisarkWordForceReference3
	dw emptySong_Subsong0_SpeedTrack0
emptySong_Subsong0_DisarkWordForceReference4
	dw emptySong_Subsong0_EventTrack0

emptySong_Subsong0_Track0
	db 61, 13

	db 124
	db 0
	db 61, 127


emptySong_Subsong0_Track1
	db 61, 25

	db 124
	db 0
	db 61, 127



emptySong_Subsong0_SpeedTrack0
	db 10
	db 253


emptySong_Subsong0_EventTrack0
	db 255

emptySong_Subsong0_DisarkByteRegionEnd0
