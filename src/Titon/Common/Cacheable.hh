<?hh // strict
/**
 * @copyright   2010-2015, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

namespace Titon\Common;

/**
 * The Cacheable trait provides functionality to cache any data from the class layer.
 * All data is unique and represented by a generated cache key.
 *
 * @package Titon\Common
 */
trait Cacheable {

    /**
     * Cached items indexed by key.
     *
     * @var \Titon\Common\CacheMap
     */
    protected CacheMap $cache = Map {};

    /**
     * Is cache on or off?
     *
     * @var bool
     */
    protected bool $cacheEnabled = true;

    /**
     * Return all the current cached items.
     *
     * @return \Titon\Common\CacheMap
     */
    public function allCache(): CacheMap {
        return $this->cache;
    }

    /**
     * Dynamically read and write from the cache at once. If the cache exists with the key return it, else execute and save the result.
     * If the value happens to be a closure, evaluate the closure and save the result.
     *
     * @param mixed $key
     * @param (function(this): mixed) $callback
     * @return mixed
     */
    public function cache(mixed $key,/* HH_FIXME[2043]: this type hint */ (function(this): mixed) $callback): mixed {
        $key = $this->createCacheKey($key);

        if ($this->hasCache($key)) {
            return $this->getCache($key);
        }

        return $this->setCache($key, $callback($this));
    }

    /**
     * Generate a cache key. If an array is passed, drill down and form a key.
     *
     * @param mixed $keys
     * @return string
     */
    public function createCacheKey(mixed $keys): string {
        if ($keys instanceof Traversable) {
            $key = '';

            foreach ($keys as $value) {
                if ($value instanceof Traversable) {
                    $key .= '-' . md5(serialize($value));
                } else if ($value) {
                    $key .= '-' . $value;
                }
            }
        } else {
            $key = $keys;
        }

        return trim((string) $key, '-');
    }

    /**
     * Empty the cache.
     *
     * @return $this
     */
    public function flushCache(): this {
        $this->allCache()->clear();

        return $this;
    }

    /**
     * Return a cached item if it exists, else return null.
     *
     * @param mixed $key
     * @return mixed
     */
    public function getCache(mixed $key): mixed {
        if (!$this->isCacheEnabled()) {
            return null;
        }

        return $this->allCache()->get($this->createCacheKey($key));
    }

    /**
     * Check to see if the cache key exists.
     *
     * @param mixed $key
     * @return bool
     */
    public function hasCache(mixed $key): bool {
        return $this->allCache()->contains($this->createCacheKey($key));
    }

    /**
     * Return true if caching is enabled.
     *
     * @return bool
     */
    public function isCacheEnabled(): bool {
        return $this->cacheEnabled;
    }

    /**
     * Remove an item from the cache. Return true if the item was removed.
     *
     * @param mixed $key
     * @return $this
     */
    public function removeCache(mixed $key): this {
        $this->allCache()->remove($this->createCacheKey($key));

        return $this;
    }

    /**
     * Set a value to the cache with the defined key.
     * This will overwrite any data with the same key.
     * The value being saved will be returned.
     *
     * @param mixed $key
     * @param mixed $value
     * @return mixed
     */
    public function setCache(mixed $key, mixed $value): mixed {
        if (!$this->isCacheEnabled()) {
            return $value;
        }

        $this->allCache()->set($this->createCacheKey($key), $value);

        return $value;
    }

    /**
     * Toggle cache on and off.
     *
     * @param bool $on
     * @return $this
     */
    public function toggleCache(bool $on = true): this {
        $this->cacheEnabled = $on;

        return $this;
    }

}
