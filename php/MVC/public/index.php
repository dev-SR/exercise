<?php
require_once __DIR__ . '/../vendor/autoload.php';

use app\Router;
use app\controllers\MainControllers;

$router = new Router();

$router->get('/', [MainControllers::class, 'index']);
$router->get('/test', [MainControllers::class, 'test']);

$router->resolve();


/**
 *  Run Custom Server.
 *  php   cd .\MVC\public\
 *  public   php -S localhost:8080
 */