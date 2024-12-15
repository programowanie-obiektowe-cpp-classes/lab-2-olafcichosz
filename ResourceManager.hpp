#pragma once

#include "Resource.hpp"
#include <memory> // std::unique_ptr

class ResourceManager
{
private:
    std::unique_ptr< Resource > resource; // Zarz�dzany zas�b (wska�nik unikalny)

public:
    // Konstruktor domy�lny: inicjalizuje nowy zas�b
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiuj�cy: kopiuje zas�b
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiuj�cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz�cy: przejmuje zas�b
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz�cy: przejmuje zas�b
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor: automatycznie zwalnia zas�b
    ~ResourceManager() = default;

    // Metoda get() zwracaj�ca wynik wywo�ania get() zarz�dzanego zasobu
    double get() const { return resource->get(); }
};
