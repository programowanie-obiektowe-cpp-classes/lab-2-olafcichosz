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

    // Konstruktor przenosz¹cy
    ResourceManager(ResourceManager&& other) noexcept : resource(other.resource)
    {
        other.resource = nullptr; // ustaw wskaŸnik w drugim obiekcie na nullptr
    }

    // Operator przypisania przenosz¹cy
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete resource;                 // zwolnij obecny zasób
            resource       = other.resource; // przenieœ zasób
            other.resource = nullptr;        // ustaw wskaŸnik w drugim obiekcie na nullptr
        }
        return *this;
    }

    // Destruktor: zwalnia zarz¹dzany zasób
    ~ResourceManager() { delete resource; }

    // Metoda get() zwracaj¹ca wynik wywo³ania get() zarz¹dzanego zasobu
    double get() const { return resource->get(); }
};
