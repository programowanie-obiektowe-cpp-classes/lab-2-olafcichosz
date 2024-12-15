#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource resource; // Zarz�dzany zas�b (bezpo�rednio jako pole klasy)

public:
    // Konstruktor domy�lny
    ResourceManager() = default;

    // Konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& other) = default;

    // Operator przypisania kopiuj�cy
    ResourceManager& operator=(const ResourceManager& other) = default;

    // Konstruktor przenosz�cy
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz�cy
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get() zwracaj�ca wynik wywo�ania get() zasobu
    double get() const { return resource.get(); }
};
