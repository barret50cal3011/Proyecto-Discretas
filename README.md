## 🧠 Propósito del Proyecto

Este proyecto fue desarrollado con el objetivo de **procesar fórmulas lógicas escritas en sintaxis LaTeX y devolver una versión equivalente, pero estructurada de forma bien formada (F.B.F.), respetando la prioridad de los operadores lógicos.**

En lógica proposicional, una **fórmula bien formada (F.B.F.)** es una expresión construida según reglas sintácticas estrictas, que garantizan su validez formal. En este caso, el proyecto toma una fórmula dada en LaTeX y reorganiza sus componentes utilizando paréntesis y reglas de prioridad, para dejar explícita la estructura lógica de la expresión.

###  Reglas de Prioridad

Las prioridades de los operadores lógicos, de mayor a menor, son las siguientes:

1. **Negación:** `\neg`
2. **Implicación y doble implicación:** `\rightarrow`, `\leftrightarrow`
3. **Conjunción y disyunción:** `\wedge`, `\vee`

Esto significa que, por ejemplo, una negación se debe aplicar antes que una conjunción, y una implicación debe agrupar sus términos antes que cualquier disyunción que esté en el mismo nivel.

## Manuel De Usuario
1. Pon tu fórmula lógica con sintaxix Latex en el archivo latex.txt
2. Ejecuta el archivo boolean.exe
3. Abre el archivo salida.tex con tu lector de latex preferido y podras ver tu fórmula lógica original y la bien formada
### Integrantes
- Daniel Barreto Calvo
- Jorley Snehider Salas Rocha
- Julian Ricardo Gonzalez Muñoz
