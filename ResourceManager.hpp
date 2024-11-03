#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource* resource; // wska�nik do zarz�dzanego zasobu typu Resource

public:
    // Konstruktor domy�lny: tworzy nowy obiekt Resource
    ResourceManager() : resource(new Resource()) {}

    // Konstruktor kopiuj�cy: tworzy kopi� zarz�dzanego zasobu
    ResourceManager(const ResourceManager& other) : resource(new Resource(*other.resource)) {}

    // Operator przypisania kopiuj�cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            delete resource;                          // zwolnij obecny zas�b
            resource = new Resource(*other.resource); // skopiuj zas�b z drugiego obiektu
        }
        return *this;
    }

    // Konstruktor przenosz�cy
    ResourceManager(ResourceManager&& other) noexcept : resource(other.resource)
    {
        other.resource = nullptr; // ustaw wska�nik w drugim obiekcie na nullptr
    }

    // Operator przypisania przenosz�cy
    ResourceManager& operator=(ResourceManager&& other) noexcept
    {
        if (this != &other) {
            delete resource;                 // zwolnij obecny zas�b
            resource       = other.resource; // przenie� zas�b
            other.resource = nullptr;        // ustaw wska�nik w drugim obiekcie na nullptr
        }
        return *this;
    }

    // Destruktor: zwalnia zarz�dzany zas�b
    ~ResourceManager() { delete resource; }

    // Metoda get() zwracaj�ca wynik wywo�ania get() zarz�dzanego zasobu
    double get() const { return resource->get(); }
};
