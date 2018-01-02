#include <rt/renderer.h>
#include <core/color.h>
#include <core/image.h>
#include <iostream>
#include <core/julia.h>
#include <core/point.h>
#include <core/vector.h>
#include <core/scalar.h>
//#include <SDL.h>
#include <rt/ray.h>
#include <rt/cameras/camera.h>
#include <rt/integrators/casting.h>
#include <main/statistics.h>


rt::RGBColor a1computeColor(rt::uint x, rt::uint y, rt::uint width, rt::uint height);
rt::RGBColor a2computeColor(const rt::Ray& r);


namespace rt {


	Renderer::Renderer(Camera* cam, Integrator* integrator)
	{
		//convert image pixel coordinates into the uniform camera coordinates
		this->cam = cam;
		this->integrator = integrator;
	}

	void Renderer::setSamples(uint samples)
	{
	}

	void Renderer::render(Image & img)
	{
		for (int i = 0; i < img.height(); i++)
		{
			for (int j = 0; j < img.width(); j++)
			{
				// normalized coordinates
				float fx = float(j) / float(img.width());
				float fy = float(i) / float(img.height());

				// camera space coordinates
				fx = fx * 2 - 1;
				fy = 1 - fy * 2;

				Statistics::numPrimaryRays++;
				const Ray ray = this->cam->getPrimaryRay(fx, fy);
				RGBColor color = this->integrator->getRadiance(ray);

				img(j, i) = color;
			}
		}
	}

	void Renderer::test_render1(Image& img)
	{
		//SDL_Window *window;
		//SDL_Renderer *renderer;
		//SDL_Init(SDL_INIT_VIDEO);
		//SDL_CreateWindowAndRenderer(img.width(), img.height(), 0, &window, &renderer);
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		//SDL_RenderClear(renderer);

		for (int i = 0; i < img.width(); i++)
		{
			for (int j = 0; j < img.height(); j++)
			{
				RGBColor color = a1computeColor(j, i, img.width(), img.height());
				//RGBColor clamped = color.clamp();
				//SDL_SetRenderDrawColor(renderer, clamped.r * 255, clamped.g * 255, clamped.b * 255, 255);
				//SDL_RenderDrawPoint(renderer, j, i);
				//SDL_RenderPresent(renderer);

				img(j, i) = color;
			}
		}
	}

	void Renderer::test_render2(Image& img)
	{
		//SDL_Window *window;
		//SDL_Renderer *renderer;
		//SDL_Init(SDL_INIT_VIDEO);
		//SDL_CreateWindowAndRenderer(img.width(), img.height(), 0, &window, &renderer);
		//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		//SDL_RenderClear(renderer);

		for (int i = 0; i < img.width(); i++)
		{
			for (int j = 0; j < img.height(); j++)
			{
				// normalized coordinates
				float fx = float(j) / float(img.width());
				float fy = float(i) / float(img.height());

				// camera space coordinates
				fx = fx * 2 - 1;
				fy = 1 - fy * 2;
				//std::cout << fx << " " << fy << std::endl;
				const Ray ray = this->cam->getPrimaryRay(fx, fy);

				RGBColor color = a2computeColor(ray);
				//RGBColor clamped = color.clamp();
				//SDL_SetRenderDrawColor(renderer, clamped.r * 255, clamped.g * 255, clamped.b * 255, 255);
				//SDL_RenderDrawPoint(renderer, j, i);
				//SDL_RenderPresent(renderer);

				img(j, i) = color;
			}
		}
	}

	
}

