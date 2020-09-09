Ejercicio 1. EL CAMIONERO CON PRISA

Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite, con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de carreteras que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a abastecer gasolina el menor número de veces posible.

Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el camionero.

Ejercicio 2. LA DIVISIÓN EN PÁRRAFOS

Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas en líneas de longitud L. Las palabras están separadas por espacios cuya amplitud ideal (en milímetros) es b, pero los espacios pueden reducirse o ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que una línea pi, pi+1, ..., pj tenga exactamente longitud L. Sin embargo, existe una penalización por reducción o ampliación en el número total de espacios que aparecen o desaparecen. El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios, es decir (L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n (la última palabra) el costo será cero a menos que b’ < b (ya que no es necesario ampliar la última línea).

Diseñe un algoritmo para resolver el problema.


Ejercicio 3. LA SUBSECUENCIA COMÚN MÁXIMA

Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia de X (siendo k ≤ m) si existe una secuencia creciente {i1 i2 ... ik} de índices de X tales que para todo j = 1, 2, ..., k tenemos xij = zj.

Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es subsecuencia de X y subsecuencia de Y. 

Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima común a dos secuencias.




Ejercicio 4. LAS PAREJAS ESTABLES

Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen las preferencias de los unos por los otros. Más concretamente, la fila M[i,·] es una ordenación (de mayor a menor) de las mujeres según las preferencias del i-ésimo hombre y, análogamente, la fila H[i,·] es una ordenación (de mayor a menor) de los hombres según las preferencias de la i-ésima mujer.

Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y mujeres tal que todas las parejas formadas sean estables. Una pareja (h,m) es estable si no se da ninguna de estas dos circunstancias:

Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere sobre la mujer m y además la mujer m’ también prefiere a h sobre h’. 
Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m lo prefiere sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”