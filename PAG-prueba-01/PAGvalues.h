#pragma once

enum PAGstipomovimiento {
	PAG_TTILT,
	PAG_PAN,
	PAG_TRUCK,
	PAG_BOOM,
	PAG_ORBIT,
	PAG_ZOOM,
	PAG_NONE,
	PAG_MROT,
	PAG_MTRANS,
	PAG_MSCALE
};

enum PAGstipoluz {
	PUNTUAL,
	SPOT,
	AMBIENTE,
	MODELO
};

enum PAGpartesRevolucion : int {
	PAG_CUERPO = 0,
	PAG_TAPA_SUP = 1,
	PAG_TAPA_INF = 2
};