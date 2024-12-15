#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource resource; // Zarz¹dzany zasób (bezpoœrednio jako pole klasy)

public:
    // Konstruktor domyœlny
    ResourceManager() = default;

    // Konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& other) = default;

    // Operator przypisania kopiuj¹cy
    ResourceManager& operator=(const ResourceManager& other) = default;

    // Konstruktor przenosz¹cy
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz¹cy
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get() zwracaj¹ca wynik wywo³ania get() zasobu
    double get() const { return resource.get(); }
};
