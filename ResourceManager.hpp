#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource; // wskaŸnik do zarz¹dzanego zasobu typu Resource

public:
    // Konstruktor domyœlny: tworzy nowy obiekt Resource
    ResourceManager() : resource(new Resource()) {}

    // Konstruktor kopiuj¹cy: tworzy kopiê zarz¹dzanego zasobu
    ResourceManager(const ResourceManager& other) : resource(new Resource(*other.resource)) {}

    // Operator przypisania kopiuj¹cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            delete resource;                          // zwolnij obecny zasób
            resource = new Resource(*other.resource); // skopiuj zasób z drugiego obiektu
        }
        return *this;
    }

    // Usuwamy semantykê przenoszenia
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    // Destruktor: zwalnia zarz¹dzany zasób
    ~ResourceManager() { delete resource; }

    // Metoda get() zwracaj¹ca wynik wywo³ania get() zarz¹dzanego zasobu
    double get() const { return resource->get(); }
};
