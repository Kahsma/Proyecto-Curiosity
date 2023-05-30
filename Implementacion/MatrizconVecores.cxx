#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <limits>

template <class T, class U>
class Grafo {
private:
    std::vector<T> vertices;
    std::vector<std::vector<U>> aristas;

public:
    Grafo() {}

    void setVertices(std::vector<T> v) {
        vertices = v;
        aristas.resize(v.size(), std::vector<U>(v.size(), 0));
    }

    void setAristas(std::vector<std::vector<U>> a) {
        aristas = a;
    }

    std::vector<T> getVertices() {
        return vertices;
    }

    std::vector<std::vector<U>> getAristas() {
        return aristas;
    }

    int cantVertices() {
        return vertices.size();
    }

    int cantAristas() {
        int suma = 0;
        for (int i = 0; i < cantVertices(); i++) {
            for (int j = 0; j < cantVertices(); j++) {
                if (aristas[i][j] != 0)
                    suma++;
            }
        }
        return suma;
    }

    int buscarVertice(T vert) {
        for (int i = 0; i < cantVertices(); i++) {
            if (vertices[i] == vert)
                return i;
        }
        return -1;
    }

    bool insertarVertice(T vert) {
        if (buscarVertice(vert) == -1) {
            vertices.push_back(vert);
            aristas.resize(cantVertices(), std::vector<U>(cantVertices(), 0));
            for (int i = 0; i < cantVertices() - 1; i++) {
                aristas[i].resize(cantVertices());
            }
            return true;
        }
        return false;
    }

    bool insertarArista(T ori, T des, U cos) {
        int i_ori = buscarVertice(ori);
        int i_des = buscarVertice(des);
        if (i_ori != -1 && i_des != -1 && aristas[i_ori][i_des] == 0) {
            aristas[i_ori][i_des] = cos;
            return true;
        }
        return false;
    }

    U buscarArista(T ori, T des) {
        int i_ori = buscarVertice(ori);
        int i_des = buscarVertice(des);
        if (i_ori != -1 && i_des != -1)
            return aristas[i_ori][i_des];
        return -1;
    }

    bool eliminarArista(T ori, T des) {
        int i_ori = buscarVertice(ori);
        int i_des = buscarVertice(des);
        if (i_ori != -1 && i_des != -1 && aristas[i_ori][i_des] != 0) {
            aristas[i_ori][i_des] = 0;
            return true;
        }
        return false;
    }

    bool eliminarVertice(T vert) {
        int vertPos = buscarVertice(vert);
        if (vertPos != -1) {
            vertices.erase(vertices.begin() + vertPos);
            aristas.erase(aristas.begin() + vertPos);
            for (int i = 0; i < cantVertices(); i++) {
                aristas[i].erase(aristas[i].begin() + vertPos);
            }
            return true;
        }
        return false;
    }

    void recorridoPlano(){
		for (char v : vertices) {
        	std::cout << v << " ";
    	}
	}


    void BusquedaDFS(T Inicio) {
        std::vector<bool> visitados(cantVertices(), false);
        int inicioIdx = buscarVertice(Inicio);
        if (inicioIdx != -1)
            dfs(inicioIdx, visitados);
    }


    void dfs(int vertice, std::vector<bool>& visitados) {
        visitados[vertice] = true;
        std::cout << vertices[vertice] << " ";

        for (int i = 0; i < cantVertices(); i++) {
            if (aristas[vertice][i] != 0 && !visitados[i]) {
                dfs(i, visitados);
            }
        }
    }

    void BusquedaBfs(T Inicio) {
        std::vector<bool> visitados(cantVertices(), false);
        int inicioIdx = buscarVertice(Inicio);
        if (inicioIdx != -1)
            bfs(inicioIdx, visitados);
    }


    void bfs(int vertice, std::vector<bool>& visitados) {
        std::queue<int> cola;
        cola.push(vertice);
        visitados[vertice] = true;

        while (!cola.empty()) {
            int v = cola.front();
            cola.pop();
            std::cout << vertices[v] << " ";

            for (int i = 0; i < cantVertices(); i++) {
                if (aristas[v][i] != 0 && !visitados[i]) {
                    cola.push(i);
                    visitados[i] = true;
                }
            }
        }
    }


    std::list<std::list<T>> componentesconectados() {
        std::vector<bool> visitados(cantVertices(), false);
        std::list<std::list<T>> componentes;

        for (int i = 0; i < cantVertices(); i++) {
            if (!visitados[i]) {
                std::list<T> componente;
                dfsComponente(i, visitados, componente);
                componentes.push_back(componente);
            }
        }

        return componentes;
    }


    void dfsComponente(int vertice, std::vector<bool>& visitados, std::list<T>& componente) {
        visitados[vertice] = true;
        componente.push_back(vertices[vertice]);

        for (int i = 0; i < cantVertices(); i++) {
            if (aristas[vertice][i] != 0 && !visitados[i]) {
                dfsComponente(i, visitados, componente);
            }
        }
    }


    std::vector<int> obtenerAdyacentes(int v) {
        std::vector<int> adyacentes;

        for (int i = 0; i < cantVertices(); i++) {
            if (aristas[v][i] != 0) {
                adyacentes.push_back(i);
            }
        }

        return adyacentes;
    }


	std::vector<std::pair<T, T>> aristaPuente() {
		std::vector<std::pair<T, T>> puentes; // Vector de puentes
		std::vector<bool> visitados(vertices.size(), false);
		std::vector<int> tiempos(vertices.size(), -1); // Tiempo de descubrimiento para cada nodo
		std::vector<int> tiemposMin(vertices.size(), -1); // Tiempo mínimo alcanzable desde cada nodo
		int tiempo = 0; // Variable para llevar el tiempo de descubrimiento

		for (int i = 0; i < cantVertices(); i++) {
			if (!visitados[i]) {
				dfsAristaPuente(i, -1, visitados, tiempos, tiemposMin, tiempo, puentes);
			}
		}

		return puentes;
	}

	void dfsAristaPuente(int nodo, int padre, std::vector<bool>& visitados, std::vector<int>& tiempos,
		std::vector<int>& tiemposMin, int& tiempo, std::vector<std::pair<T, T>>& puentes) {
		visitados[nodo] = true;
		tiempos[nodo] = tiempo;
		tiemposMin[nodo] = tiempo;
		tiempo++;

		for (int i = 0; i < vertices.size(); i++) {
			if (aristas[nodo][i] != 0) {
				if (!visitados[i]) {
					dfsAristaPuente(i, nodo, visitados, tiempos, tiemposMin, tiempo, puentes);
					tiemposMin[nodo] = std::min(tiemposMin[nodo], tiemposMin[i]);

					if (tiempos[nodo] < tiemposMin[i]) {
						puentes.push_back(std::make_pair(vertices[nodo], vertices[i]));
					}
				}
				else if (i != padre) {
					tiemposMin[nodo] = std::min(tiemposMin[nodo], tiempos[i]);
				}
			}
		}
	}


    std::vector<int> algoritmoFleury() {
        std::vector<int> eulerPath;

        // Verificar si hay un camino Euleriano válido
        if (!verificarCaminoEuleriano()) {
            return eulerPath;
        }

        // Crear una copia de la matriz de aristas
        std::vector<std::vector<U>> aristasRestantes = aristas;

        // Obtener un vértice de inicio para el camino Euleriano
        int inicio = obtenerVerticeInicio();

        // Iniciar el recorrido Euleriano
        dfsFleury(inicio, aristasRestantes, eulerPath);

        return eulerPath;
    }

    void dfsFleury(int vertice, std::vector<std::vector<U>>& aristasRestantes, std::vector<int>& eulerPath) {
        for (int i = 0; i < cantVertices(); i++) {
            if (aristasRestantes[vertice][i] != 0) {
                // Verificar si la arista es un puente
                if (esAristaPuente(vertice, i, aristasRestantes)) {
                    continue;
                }

                // Eliminar la arista del grafo
                aristasRestantes[vertice][i] = 0;
                aristasRestantes[i][vertice] = 0;

                // Realizar el recorrido DFS en el subgrafo modificado
                dfsFleury(i, aristasRestantes, eulerPath);
            }
        }

        // Agregar el vértice al camino Euleriano
        eulerPath.push_back(vertice);
    }

    bool esAristaPuente(int vertice1, int vertice2, const std::vector<std::vector<U>>& aristasRestantes) {
        // Crear una copia temporal de las aristas para realizar la verificación
        std::vector<std::vector<U>> tempAristas = aristasRestantes;
        tempAristas[vertice1][vertice2] = 0;
        tempAristas[vertice2][vertice1] = 0;

        // Verificar si el grafo sigue siendo conexo después de eliminar la arista
        std::vector<bool> visitados(cantVertices(), false);
        dfsPuente(0, tempAristas, visitados);

        // Si existen vértices no visitados, la arista es un puente
        for (int i = 0; i < cantVertices(); i++) {
            if (!visitados[i]) {
                return true;
            }
        }

        return false;
    }

    void dfsPuente(int vertice, const std::vector<std::vector<U>>& aristasRestantes, std::vector<bool>& visitados) {
        visitados[vertice] = true;

        for (int i = 0; i < cantVertices(); i++) {
            if (aristasRestantes[vertice][i] != 0 && !visitados[i]) {
                dfsPuente(i, aristasRestantes, visitados);
            }
        }
    }

    bool verificarCaminoEuleriano() {
        int contadorImpar = 0;

        for (int i = 0; i < cantVertices(); i++) {
            int grado = 0;

            for (int j = 0; j < cantVertices(); j++) {
                if (aristas[i][j] != 0) {
                    grado++;
                }
            }

            if (grado % 2 != 0) {
                contadorImpar++;
            }
        }

        return contadorImpar == 0 || contadorImpar == 2;
    }

    int obtenerVerticeInicio() {
        int verticeInicio = -1;

        for (int i = 0; i < cantVertices(); i++) {
            int grado = 0;

            for (int j = 0; j < cantVertices(); j++) {
                if (aristas[i][j] != 0) {
                    grado++;
                }
            }

            if (grado % 2 != 0) {
                return i;
            } else if (verticeInicio == -1 && grado > 0) {
                verticeInicio = i;
            }
        }

        return verticeInicio;
    }


    

    void dijkstras(T origen) {
        // Obtener el índice del vértice de origen
        int origenIdx = buscarVertice(origen);
        if (origenIdx == -1) {
            std::cout << "El vertice de origen no existe." << std::endl;
            return;
        }

        // Crear vectores para almacenar las distancias y los padres de cada vértice
        std::vector<U> distancias(cantVertices(), std::numeric_limits<U>::max());
        std::vector<int> padres(cantVertices(), -1);

        // Establecer la distancia del vértice de origen como 0
        distancias[origenIdx] = 0;

        // Crear una cola de prioridad para almacenar los vértices y sus distancias
        std::priority_queue<std::pair<U, int>, std::vector<std::pair<U, int>>, std::greater<std::pair<U, int>>> pq;

        // Insertar el vértice de origen en la cola de prioridad
        pq.push(std::make_pair(distancias[origenIdx], origenIdx));

        while (!pq.empty()) {
            // Obtener el vértice con la menor distancia actual
            int u = pq.top().second;
            pq.pop();

            // Obtener los vértices adyacentes a u
            std::vector<int> adyacentes = obtenerAdyacentes(u);

            // Recorrer los vértices adyacentes a u
            for (int v : adyacentes) {
                // Obtener el costo de la arista entre u y v
                U costo = aristas[u][v];

                // Calcular la nueva distancia tentativa desde el origen hasta v
                U distanciaTentativa = distancias[u] + costo;

                // Si la nueva distancia es menor a la distancia actual almacenada para v, actualizarla
                if (distanciaTentativa < distancias[v]) {
                    distancias[v] = distanciaTentativa;
                    padres[v] = u;
                    pq.push(std::make_pair(distancias[v], v));
                }
            }
        }

        // Imprimir los resultados
        std::cout << "Distancias desde el vertice de origen (" << origen << "):" << std::endl;
        for (int i = 0; i < cantVertices(); i++) {
            if (distancias[i] == std::numeric_limits<U>::max()) {
                std::cout << vertices[i] << ": No alcanzable" << std::endl;
            } else {
                std::cout << vertices[i] << ": " << distancias[i] << std::endl;
            }
        }

        // Imprimir los caminos más cortos
        std::cout << "Caminos mas cortos:" << std::endl;
        for (int i = 0; i < cantVertices(); i++) {
            if (i == origenIdx) {
                continue;
            }

            std::cout << "Desde el vertice de origen (" << origen << ") hasta " << vertices[i] << ": ";
            std::stack<T> camino;

            // Reconstruir el camino desde el vértice i hasta el origen
            int v = i;
            while (v != -1) {
                camino.push(vertices[v]);
                v = padres[v];
            }

            // Imprimir el camino
            while (!camino.empty()) {
                std::cout << camino.top();
                camino.pop();
                if (!camino.empty()) {
                    std::cout << " -> ";
                }
            }

            std::cout << std::endl;
        }
    }

    void longestPathDijkstra(T origen) {
        // Obtener el índice del vértice de origen
        int origenIdx = buscarVertice(origen);
        if (origenIdx == -1) {
            std::cout << "El vertice de origen no existe." << std::endl;
            return;
        }

        // Crear vectores para almacenar las distancias y los padres de cada vértice
        std::vector<U> distancias(cantVertices(), std::numeric_limits<U>::min());
        std::vector<int> padres(cantVertices(), -1);

        // Establecer la distancia del vértice de origen como 0
        distancias[origenIdx] = 0;

        // Crear una cola de prioridad para almacenar los vértices y sus distancias
        std::priority_queue<std::pair<U, int>> pq;
        // Insertar el vértice de origen en la cola de prioridad
        pq.push(std::make_pair(distancias[origenIdx], origenIdx));

        while (!pq.empty()) {
            // Obtener el vértice con la mayor distancia actual
            int u = pq.top().second;
            pq.pop();

            // Obtener los vértices adyacentes a u
            std::vector<int> adyacentes = obtenerAdyacentes(u);

            // Recorrer los vértices adyacentes a u
            for (int v : adyacentes) {
                // Obtener el costo de la arista entre u y v
                U costo = aristas[u][v];

                // Calcular la nueva distancia tentativa desde el origen hasta v
                U distanciaTentativa = distancias[u] + costo;

                // Si la nueva distancia es mayor a la distancia actual almacenada para v, actualizarla
                if (distanciaTentativa > distancias[v]) {
                    distancias[v] = distanciaTentativa;
                    padres[v] = u;

                    // Insertar v en la cola de prioridad para ser procesado posteriormente
                    pq.push(std::make_pair(distancias[v], v));
                }
            }
        }

        // Imprimir el camino más largo desde el origen a cada vértice
        std::cout << "Camino más largo desde el origen (" << origen << "):" << std::endl;
        for (int i = 0; i < cantVertices(); i++) {
            if (distancias[i] != std::numeric_limits<U>::min()) {
                std::cout << "Vertice: " << vertices[i] << ", Distancia: " << distancias[i] << ", Camino: ";

                // Reconstruir el camino desde el origen hasta el vértice i
                std::stack<T> camino;
                int v = i;
                while (v != origenIdx) {
                    camino.push(vertices[v]);
                    v = padres[v];
                }
                camino.push(origen);

                // Imprimir el camino en orden
                while (!camino.empty()) {
                    std::cout << camino.top();
                    camino.pop();
                    if (!camino.empty()) {
                        std::cout << " -> ";
                    }
                }

                std::cout << std::endl;
            }
        }
    }
    


    std::vector<std::pair<T, T>> prim() {
        std::vector<std::pair<T, T>> mst; // Minimum Spanning Tree
        std::vector<U> distancias(cantVertices(), std::numeric_limits<U>::max()); // Distances from the MST to each vertex
        std::vector<int> padres(cantVertices(), -1); // Parents of each vertex in the MST
        std::vector<bool> visitados(cantVertices(), false); // Visited vertices

        // Choose an arbitrary vertex as the starting point
        int inicio = 0;
        distancias[inicio] = 0;

        for (int i = 0; i < cantVertices() - 1; i++) {
            // Find the vertex with the minimum distance from the MST
            int minDist = std::numeric_limits<U>::max();
            int u;

            for (int v = 0; v < cantVertices(); v++) {
                if (!visitados[v] && distancias[v] < minDist) {
                    minDist = distancias[v];
                    u = v;
                }
            }

            visitados[u] = true;

            // Add the edge (padres[u], u) to the MST
            if (padres[u] != -1) {
                mst.push_back(std::make_pair(vertices[padres[u]], vertices[u]));
            }

            // Update the distances and parents of the adjacent vertices
            for (int v = 0; v < cantVertices(); v++) {
                if (!visitados[v] && aristas[u][v] != 0 && aristas[u][v] < distancias[v]) {
                    distancias[v] = aristas[u][v];
                    padres[v] = u;
                }
            }
        }

        return mst;
    }

   
};
