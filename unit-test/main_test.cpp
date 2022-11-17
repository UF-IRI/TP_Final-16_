#include "gmock/gmock.h"
#include "funciones.h"

namespace foobar::tests {
	TEST(ExampleTests, Example) {
        ASSERT_THAT(1, 1);
	}

	TEST(TestFunciones, Prueba1) {
		tm fecha1, fecha2;
		fecha1.tm_year = 2001;
		fecha2.tm_year = 2001;
		fecha1.tm_mon = 11;
		fecha2.tm_mon = 11;
		fecha1.tm_wday = 2;
		fecha2.tm_wday = 7;
		ASSERT_TRUE(compararFechas(fecha1, fecha2));
		cout << "----PRIMERA PRUEBA A FUNCION PASADA----" << endl;
	}

	TEST(TestFunciones, Prueba2) {
		tm fecha1;
		fecha1.tm_year = 2022;
		fecha1.tm_mon = 11;
		fecha1.tm_wday = 5;
		ASSERT_THAT(PasaStringaFecha("05/11/2022"), fecha1);
		cout << "----SEGUNDA PRUEBA A FUNCION PASADA----" << endl;
	}

	TEST(TestFunciones, Prueba3) {
		tm fecha1, fecha2;
		fecha1.tm_year = 2001;
		fecha2.tm_year = 2009;
		fecha1.tm_mon = 11;
		fecha2.tm_mon = 11;
		fecha1.tm_wday = 2;
		fecha2.tm_wday = 7;
		ASSERT_FALSE(MayorDiezAnios(fecha1, fecha2));
		cout << "----TERCERA PRUEBA A FUNCION PASADA----" << endl;
	}

	TEST(TestFunciones, Prueba4) {
		tm fecha1, fecha2;
		fecha1.tm_year = 2001;
		fecha2.tm_year = 2011;
		fecha1.tm_mon = 11;
		fecha2.tm_mon = 11;
		fecha1.tm_wday = 2;
		fecha2.tm_wday = 7;
		ASSERT_TRUE(MayorDiezAnios(fecha1, fecha2));
		cout << "----CUARTA PRUEBA A FUNCION PASADA----" << endl;
	}
}
