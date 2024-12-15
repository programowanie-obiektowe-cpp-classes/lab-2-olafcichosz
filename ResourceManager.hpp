#pragma once

#include "Resource.hpp"
#include <memory> // std::unique_ptr

class ResourceManager
{
private:
    std::unique_ptr< Resource > resource; // Zarz¹dzany zasób (wskaŸnik unikalny)

public:
    // Konstruktor domyœlny: inicjalizuje nowy zasób
    ResourceManager() : resource(std::make_unique< Resource >()) {}

    // Konstruktor kopiuj¹cy: kopiuje zasób
    ResourceManager(const ResourceManager& other)
        : resource(std::make_unique< Resource >(*other.resource))
    {}

    // Operator przypisania kopiuj¹cy
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource = std::make_unique< Resource >(*other.resource);
        }
        return *this;
    }

    // Konstruktor przenosz¹cy: przejmuje zasób
    ResourceManager(ResourceManager&& other) noexcept = default;

    // Operator przypisania przenosz¹cy: przejmuje zasób
    ResourceManager& operator=(ResourceManager&& other) noexcept = default;

    // Destruktor: automatycznie zwalnia zasób
    ~ResourceManager() = default;

    // Metoda get() zwracaj¹ca wynik wywo³ania get() zarz¹dzanego zasobu
    double get() const { return resource->get(); }
};
