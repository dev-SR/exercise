<?php


namespace app;


class Router
{
    public array $getRoutes = [];

    public function get($url, $fn)
    {
        $this->getRoutes[$url] = $fn;
    }

    public function resolve()
    {
        $currentURL = $_SERVER['PATH_INFO'] ?? '/';
        $method = $_SERVER['REQUEST_METHOD'];

        if ($method == "GET") {
            $fn = $this->getRoutes[$currentURL];
            $controller = new $fn[0]; // Create New Instance
            call_user_func(array($controller, $fn[1])); // Callback

            echo '<pre>';
            print_r($fn);
            echo '</pre>';
        }
    }
}
