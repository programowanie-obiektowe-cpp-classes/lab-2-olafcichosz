#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    Resource resource; // Zarządzany zasób (bezpośrednio jako pole klasy)

public:
    // Konstruktor domyślny
    ResourceManager() = default;

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) = default;

    // Operator przypisania kopiujący
    ResourceManager& operator=(const ResourceManager& other) = default;

    // Konstruktor przenoszący
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenoszący
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get() zwracająca wynik wywołania get() zasobu
    double get() const { return resource.get(); }
};
