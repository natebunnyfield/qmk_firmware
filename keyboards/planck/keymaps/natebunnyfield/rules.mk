ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif
RGBLIGHT_ENABLE = no

TAP_DANCE_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes
