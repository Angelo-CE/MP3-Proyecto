#include <stddef.h> // Fix NULL
#include "hardware_interface.h"
#include "minimal_io.h"

void hardware_real_init(void) {
    debug_puts("Inicializando hardware real");
    // Aquí iría la configuración de registros específicos
    // Ejemplo: habilitar interrupciones para botones
}
