<?hh // strict
/**
 * @copyright   2010-2015, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

namespace Titon\Route;

/**
 * Filters can be used to hook into the routing cycle when a route is matched.
 * Useful for wrapping routes in auth groups, or admin groups.
 *
 * @package Titon\Route
 */
interface Filter {

    /**
     * Method to be triggered once a route has been matched.
     * The matching route and the router are passed as arguments.
     *
     * @param \Titon\Route\Router $router
     * @param \Titon\Route\Route $route
     * @return void
     */
    public function filter(Router $router, Route $route): void;

}